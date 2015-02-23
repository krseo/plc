#
# OMNeT++/OMNEST Makefile for plc
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = plc$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Isrc \
    -Isrc/Messages \
    -Isrc/PlcApp \
    -Isrc/PlcBus \
    -Isrc/PlcNic \
    -Isrc/PlcNic/PlcMac \
    -Isrc/PlcNic/PlcPhy \
    -Isrc/Plctst

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/src/PlcApp/PlcApp.o \
    $O/src/PlcBus/PlcBus.o \
    $O/src/PlcNic/PlcMac/PlcMac.o \
    $O/src/PlcNic/PlcPhy/PlcPhy.o \
    $O/src/Messages/PlcFrame_m.o \
    $O/src/Messages/PlcPkt_m.o \
    $O/src/Messages/PlcSignal_m.o

# Message files
MSGFILES = \
    src/Messages/PlcFrame.msg \
    src/Messages/PlcPkt.msg \
    src/Messages/PlcSignal.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f plc plc.exe libplc.so libplc.a libplc.dll libplc.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f src/*_m.cc src/*_m.h
	$(Q)-rm -f src/Messages/*_m.cc src/Messages/*_m.h
	$(Q)-rm -f src/PlcApp/*_m.cc src/PlcApp/*_m.h
	$(Q)-rm -f src/PlcBus/*_m.cc src/PlcBus/*_m.h
	$(Q)-rm -f src/PlcNic/*_m.cc src/PlcNic/*_m.h
	$(Q)-rm -f src/PlcNic/PlcMac/*_m.cc src/PlcNic/PlcMac/*_m.h
	$(Q)-rm -f src/PlcNic/PlcPhy/*_m.cc src/PlcNic/PlcPhy/*_m.h
	$(Q)-rm -f src/Plctst/*_m.cc src/Plctst/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc src/*.cc src/Messages/*.cc src/PlcApp/*.cc src/PlcBus/*.cc src/PlcNic/*.cc src/PlcNic/PlcMac/*.cc src/PlcNic/PlcPhy/*.cc src/Plctst/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/Messages/PlcFrame_m.o: src/Messages/PlcFrame_m.cc \
	src/Messages/PlcFrame_m.h
$O/src/Messages/PlcPkt_m.o: src/Messages/PlcPkt_m.cc \
	src/Messages/PlcPkt_m.h
$O/src/Messages/PlcSignal_m.o: src/Messages/PlcSignal_m.cc \
	src/Messages/PlcSignal_m.h
$O/src/PlcApp/PlcApp.o: src/PlcApp/PlcApp.cc \
	src/Messages/PlcFrame_m.h \
	src/Messages/PlcPkt_m.h \
	src/PlcApp/PlcApp.h
$O/src/PlcBus/PlcBus.o: src/PlcBus/PlcBus.cc \
	src/PlcBus/PlcBus.h
$O/src/PlcNic/PlcMac/PlcMac.o: src/PlcNic/PlcMac/PlcMac.cc \
	src/Messages/PlcFrame_m.h \
	src/Messages/PlcSignal_m.h \
	src/PlcNic/PlcMac/PlcMac.h
$O/src/PlcNic/PlcPhy/PlcPhy.o: src/PlcNic/PlcPhy/PlcPhy.cc \
	src/Messages/PlcSignal_m.h \
	src/PlcNic/PlcPhy/PlcPhy.h

