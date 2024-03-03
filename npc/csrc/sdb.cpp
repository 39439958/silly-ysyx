#include <common.h>
#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

void npc_exec(int n);
void reg_display();
extern "C" void pmem_read(int raddr, int *rdata);


static char* rl_gets() {
    static char *line_read = NULL;

    if (line_read) {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read) {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args) {
    npc_exec(-1);
    return npc_state;
}

static int cmd_q(char *args) {
    npc_state = 1;
    return 1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static struct {
    const char *name;
    const char *description;
    int (*handler) (char *);
} cmd_table [] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit NPC", cmd_q },
    { "si", "Step through N instructions", cmd_si},
    { "info", "Show the infomation of reg and watch point", cmd_info},
    { "x", "Examine memory", cmd_x},
};

static int cmd_help(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL) {
        /* no argument given */
        for (i = 0; i < NR_CMD; i ++) {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else {
        for (i = 0; i < NR_CMD; i ++) {
            if (strcmp(arg, cmd_table[i].name) == 0) {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

static int cmd_si(char *args) {
    int n = 0;
    if (args == NULL)
        n = 1;
    else
        sscanf(args, "%d", &n);
    npc_exec(n);
    return npc_state;
}

static int cmd_info(char *args) {
    if (strcmp(args, "r") == 0) {
        reg_display();

    } else {
        printf("Unknow parma\n");
    }
    return 0;
}

static int cmd_x(char *args) {
    int n;
    uint32_t addr;
    sscanf(args, "%d 0x%x", &n, &addr);
    for (int i = 0; i < n; i++) {
        uint32_t data;
        pmem_read(addr + i * 4, (int *)&data);
        printf("0x%08x: 0x%08x\n", addr + i * 4, data);
    }
    return 0;
}

void sdb_mainloop() {
  for (char *str; (str = rl_gets()) != NULL; ) {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL) { 
            continue; 
        }

        /* treat the remaining string as the arguments,
        * which may need further parsing
        */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end) {
            args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i ++) {
        if (strcmp(cmd, cmd_table[i].name) == 0) {
            if (cmd_table[i].handler(args) != 0) { 
                return;
            }
                break;
            }
        }
        if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    }
}