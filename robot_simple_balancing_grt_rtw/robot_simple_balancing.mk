###########################################################################
## Makefile generated for Simulink model 'robot_simple_balancing'. 
## 
## Makefile     : robot_simple_balancing.mk
## Generated on : Sun Mar 01 15:02:51 2020
## MATLAB Coder version: 4.3 (R2019b)
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\robot_simple_balancing.exe
## Product type : executable
## Build type   : Top-Level Standalone Executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = robot_simple_balancing
MAKEFILE                  = robot_simple_balancing.mk
MATLAB_ROOT               = D:\Program Files\MATLAB
MATLAB_BIN                = D:\Program Files\MATLAB\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = D:\YYCThesis\Thesis\husky_simple_balancing_sim
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = robot_simple_balancing_comp.rsp
CMD_FILE                  = robot_simple_balancing.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
LIBSM_SSCI_VCX64_OBJS     = 
LIBSM_VCX64_OBJS          = 
LIBPM_MATH_VCX64_OBJS     = 
LIBSSC_SLI_VCX64_OBJS     = 
LIBSSC_CORE_VCX64_OBJS    = 
LIBNE_VCX64_OBJS          = 
LIBMC_VCX64_OBJS          = 
LIBEX_VCX64_OBJS          = 
LIBPM_VCX64_OBJS          = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)
# Supported Version(s):    16.0
# ToolchainInfo Version:   2019b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /Od /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\robot_simple_balancing.exe
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_IMPLIED = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=robot_simple_balancing -DNUMST=2 -DNCSTATES=53 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_create.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_setParameters.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_asserts.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_deriv.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_checkDynamics.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_output.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_asm_delegate.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_sim_delegate.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_mode_zero_crossings.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_geometries.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_f30145f9_1_gateway.c $(START_DIR)\robot_simple_balancing_grt_rtw\pm_printf.c $(MATLAB_ROOT)\rtw\c\src\rt_logging.c $(START_DIR)\robot_simple_balancing_grt_rtw\rt_backsubrr_dbl.c $(START_DIR)\robot_simple_balancing_grt_rtw\rt_forwardsubrr_dbl.c $(START_DIR)\robot_simple_balancing_grt_rtw\rt_lu_real.c $(START_DIR)\robot_simple_balancing_grt_rtw\rt_matrixlib_dbl.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing.c $(START_DIR)\robot_simple_balancing_grt_rtw\robot_simple_balancing_data.c $(START_DIR)\robot_simple_balancing_grt_rtw\rtGetInf.c $(START_DIR)\robot_simple_balancing_grt_rtw\rtGetNaN.c $(START_DIR)\robot_simple_balancing_grt_rtw\rt_nonfinite.c

MAIN_SRC = $(MATLAB_ROOT)\rtw\c\src\common\rt_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = robot_simple_balancing_f30145f9_1.obj robot_simple_balancing_f30145f9_1_create.obj robot_simple_balancing_f30145f9_1_setParameters.obj robot_simple_balancing_f30145f9_1_asserts.obj robot_simple_balancing_f30145f9_1_deriv.obj robot_simple_balancing_f30145f9_1_checkDynamics.obj robot_simple_balancing_f30145f9_1_output.obj robot_simple_balancing_f30145f9_1_asm_delegate.obj robot_simple_balancing_f30145f9_1_sim_delegate.obj robot_simple_balancing_f30145f9_1_mode_zero_crossings.obj robot_simple_balancing_f30145f9_1_geometries.obj robot_simple_balancing_f30145f9_1_gateway.obj pm_printf.obj rt_logging.obj rt_backsubrr_dbl.obj rt_forwardsubrr_dbl.obj rt_lu_real.obj rt_matrixlib_dbl.obj robot_simple_balancing.obj robot_simple_balancing_data.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj

MAIN_OBJ = rt_main.obj

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = D:\Program Files\MATLAB\toolbox\physmod\sm\ssci\lib\win64\sm_ssci_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\sm\core\lib\win64\sm_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\pm_math\lib\win64\pm_math_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\network_engine\lib\win64\ne_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\common\math\core\lib\win64\mc_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\common\external\library\lib\win64\ex_vcx64.lib D:\Program Files\MATLAB\toolbox\physmod\common\foundation\core\lib\win64\pm_vcx64.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


buildobj : set_environment_variables prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@cmd /C "@echo ### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@cmd /C "@echo ### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@cmd /C "@echo ### Done invoking postbuild tool."


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@cmd /C "@echo ### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\math\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\lang\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\external\library\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c\win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\robot_simple_balancing_grt_rtw}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src\common}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


#------------------------
# BUILDABLE LIBRARIES
#------------------------

D:\Program Files\MATLAB\toolbox\physmod\sm\ssci\lib\win64\sm_ssci_vcx64.lib : $(LIBSM_SSCI_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSM_SSCI_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\sm\core\lib\win64\sm_vcx64.lib : $(LIBSM_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSM_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\pm_math\lib\win64\pm_math_vcx64.lib : $(LIBPM_MATH_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBPM_MATH_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_vcx64.lib : $(LIBSSC_SLI_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSSC_SLI_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_vcx64.lib : $(LIBSSC_CORE_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBSSC_CORE_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\network_engine\lib\win64\ne_vcx64.lib : $(LIBNE_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBNE_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\common\math\core\lib\win64\mc_vcx64.lib : $(LIBMC_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBMC_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\common\external\library\lib\win64\ex_vcx64.lib : $(LIBEX_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBEX_VCX64_OBJS)


D:\Program Files\MATLAB\toolbox\physmod\common\foundation\core\lib\win64\pm_vcx64.lib : $(LIBPM_VCX64_OBJS)
	@cmd /C "@echo ### Creating static library $@ ..."
	$(AR) $(ARFLAGS) -out:$@ $(LIBPM_VCX64_OBJS)


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


