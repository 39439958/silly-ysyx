VERILATOR = verilator
VERILATOR_CFLAGS += -cc --exe --build --trace -j

# project source
CSRCS = $(NPC_HOME)/csrc/*.cpp
VSRCS = $(NPC_HOME)/vsrc/*.v


run: 
	$(VERILATOR) $(VERILATOR_CFLAGS) $(VSRCS) $(CSRCS)
	./obj_dir/Vtop IMG=$(IMAGE).bin
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	
clean:
	rm -rf obj_dir

.PHONY: clean sim

include ../Makefile
