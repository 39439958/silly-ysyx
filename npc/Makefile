VERILATOR = verilator
VERILATOR_CFLAGS += -cc --build --exe --trace -CFLAGS "$(shell llvm-config --cxxflags) -I $(NPC_HOME)/csrc  -fPIE" -LDFLAGS "-lLLVM-14 -lreadline" 

# project source
CSRCS = $(NPC_HOME)/csrc/*.cpp $(NPC_HOME)/csrc/*.cc 
VSRCS = $(NPC_HOME)/vsrc/*.v  

IMG ?=
NEMU_EXEC := ./obj_dir/Vtop $(IMG)

run: 
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VSRCS) $(CSRCS)
	$(NEMU_EXEC)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	
clean:
	rm -rf obj_dir

.PHONY: clean run

include ../Makefile
