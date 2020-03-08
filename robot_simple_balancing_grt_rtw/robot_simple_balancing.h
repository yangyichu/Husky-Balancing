/*
 * robot_simple_balancing.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "robot_simple_balancing".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Sun Mar  1 15:02:40 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_robot_simple_balancing_h_
#define RTW_HEADER_robot_simple_balancing_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef robot_simple_balancing_COMMON_INCLUDES_
# define robot_simple_balancing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "robot_simple_balancing_f30145f9_1_gateway.h"
#endif                             /* robot_simple_balancing_COMMON_INCLUDES_ */

#include "robot_simple_balancing_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Delay[9];                     /* '<Root>/Delay' */
  real_T INPUT_1_1_1[4];               /* '<S29>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S29>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S29>/INPUT_3_1_1' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T INPUT_4_1_1[4];               /* '<S29>/INPUT_4_1_1' */
  real_T Sum[16];                      /* '<Root>/Sum' */
  real_T INPUT_23_1_1[4];              /* '<S29>/INPUT_23_1_1' */
  real_T INPUT_21_1_1[4];              /* '<S29>/INPUT_21_1_1' */
  real_T INPUT_22_1_1[4];              /* '<S29>/INPUT_22_1_1' */
  real_T INPUT_24_1_1[4];              /* '<S29>/INPUT_24_1_1' */
  real_T INPUT_27_1_1[4];              /* '<S29>/INPUT_27_1_1' */
  real_T INPUT_25_1_1[4];              /* '<S29>/INPUT_25_1_1' */
  real_T INPUT_26_1_1[4];              /* '<S29>/INPUT_26_1_1' */
  real_T INPUT_28_1_1[4];              /* '<S29>/INPUT_28_1_1' */
  real_T INPUT_31_1_1[4];              /* '<S29>/INPUT_31_1_1' */
  real_T INPUT_29_1_1[4];              /* '<S29>/INPUT_29_1_1' */
  real_T INPUT_30_1_1[4];              /* '<S29>/INPUT_30_1_1' */
  real_T INPUT_32_1_1[4];              /* '<S29>/INPUT_32_1_1' */
  real_T INPUT_35_1_1[4];              /* '<S29>/INPUT_35_1_1' */
  real_T INPUT_33_1_1[4];              /* '<S29>/INPUT_33_1_1' */
  real_T INPUT_34_1_1[4];              /* '<S29>/INPUT_34_1_1' */
  real_T INPUT_36_1_1[4];              /* '<S29>/INPUT_36_1_1' */
  real_T STATE_1[13];                  /* '<S29>/STATE_1' */
  real_T OUTPUT_1_0[80];               /* '<S29>/OUTPUT_1_0' */
  real_T FSph[12];                     /* '<S12>/Merge' */
  real_T FSph_f[12];                   /* '<S13>/Merge' */
  real_T FSph_n[12];                   /* '<S14>/Merge' */
  real_T FSph_fe[12];                  /* '<S15>/Merge' */
  real_T INPUT_8_1_1[4];               /* '<S29>/INPUT_8_1_1' */
  real_T INPUT_8_1_2[4];               /* '<S29>/INPUT_8_1_2' */
  real_T INPUT_8_1_3[4];               /* '<S29>/INPUT_8_1_3' */
  real_T INPUT_7_1_1[4];               /* '<S29>/INPUT_7_1_1' */
  real_T INPUT_7_1_2[4];               /* '<S29>/INPUT_7_1_2' */
  real_T INPUT_7_1_3[4];               /* '<S29>/INPUT_7_1_3' */
  real_T INPUT_5_1_1[4];               /* '<S29>/INPUT_5_1_1' */
  real_T INPUT_5_1_2[4];               /* '<S29>/INPUT_5_1_2' */
  real_T INPUT_5_1_3[4];               /* '<S29>/INPUT_5_1_3' */
  real_T INPUT_6_1_1[4];               /* '<S29>/INPUT_6_1_1' */
  real_T INPUT_6_1_2[4];               /* '<S29>/INPUT_6_1_2' */
  real_T INPUT_6_1_3[4];               /* '<S29>/INPUT_6_1_3' */
  real_T INPUT_12_1_1[4];              /* '<S29>/INPUT_12_1_1' */
  real_T INPUT_12_1_2[4];              /* '<S29>/INPUT_12_1_2' */
  real_T INPUT_12_1_3[4];              /* '<S29>/INPUT_12_1_3' */
  real_T INPUT_11_1_1[4];              /* '<S29>/INPUT_11_1_1' */
  real_T INPUT_11_1_2[4];              /* '<S29>/INPUT_11_1_2' */
  real_T INPUT_11_1_3[4];              /* '<S29>/INPUT_11_1_3' */
  real_T INPUT_9_1_1[4];               /* '<S29>/INPUT_9_1_1' */
  real_T INPUT_9_1_2[4];               /* '<S29>/INPUT_9_1_2' */
  real_T INPUT_9_1_3[4];               /* '<S29>/INPUT_9_1_3' */
  real_T INPUT_10_1_1[4];              /* '<S29>/INPUT_10_1_1' */
  real_T INPUT_10_1_2[4];              /* '<S29>/INPUT_10_1_2' */
  real_T INPUT_10_1_3[4];              /* '<S29>/INPUT_10_1_3' */
  real_T INPUT_16_1_1[4];              /* '<S29>/INPUT_16_1_1' */
  real_T INPUT_16_1_2[4];              /* '<S29>/INPUT_16_1_2' */
  real_T INPUT_16_1_3[4];              /* '<S29>/INPUT_16_1_3' */
  real_T INPUT_15_1_1[4];              /* '<S29>/INPUT_15_1_1' */
  real_T INPUT_15_1_2[4];              /* '<S29>/INPUT_15_1_2' */
  real_T INPUT_15_1_3[4];              /* '<S29>/INPUT_15_1_3' */
  real_T INPUT_13_1_1[4];              /* '<S29>/INPUT_13_1_1' */
  real_T INPUT_13_1_2[4];              /* '<S29>/INPUT_13_1_2' */
  real_T INPUT_13_1_3[4];              /* '<S29>/INPUT_13_1_3' */
  real_T INPUT_14_1_1[4];              /* '<S29>/INPUT_14_1_1' */
  real_T INPUT_14_1_2[4];              /* '<S29>/INPUT_14_1_2' */
  real_T INPUT_14_1_3[4];              /* '<S29>/INPUT_14_1_3' */
  real_T INPUT_20_1_1[4];              /* '<S29>/INPUT_20_1_1' */
  real_T INPUT_20_1_2[4];              /* '<S29>/INPUT_20_1_2' */
  real_T INPUT_20_1_3[4];              /* '<S29>/INPUT_20_1_3' */
  real_T INPUT_19_1_1[4];              /* '<S29>/INPUT_19_1_1' */
  real_T INPUT_19_1_2[4];              /* '<S29>/INPUT_19_1_2' */
  real_T INPUT_19_1_3[4];              /* '<S29>/INPUT_19_1_3' */
  real_T INPUT_17_1_1[4];              /* '<S29>/INPUT_17_1_1' */
  real_T INPUT_17_1_2[4];              /* '<S29>/INPUT_17_1_2' */
  real_T INPUT_17_1_3[4];              /* '<S29>/INPUT_17_1_3' */
  real_T INPUT_18_1_1[4];              /* '<S29>/INPUT_18_1_1' */
  real_T INPUT_18_1_2[4];              /* '<S29>/INPUT_18_1_2' */
  real_T INPUT_18_1_3[4];              /* '<S29>/INPUT_18_1_3' */
  real_T x;                            /* '<Root>/MATLAB Function1' */
  real_T y;                            /* '<Root>/MATLAB Function1' */
  real_T z;                            /* '<Root>/MATLAB Function1' */
  real_T d_leg[16];                    /* '<Root>/MATLAB Function1' */
} B_robot_simple_balancing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[9];              /* '<Root>/Delay' */
  real_T INPUT_1_1_1_Discrete;         /* '<S29>/INPUT_1_1_1' */
  real_T INPUT_1_1_1_FirstOutput;      /* '<S29>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete;         /* '<S29>/INPUT_2_1_1' */
  real_T INPUT_2_1_1_FirstOutput;      /* '<S29>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete;         /* '<S29>/INPUT_3_1_1' */
  real_T INPUT_3_1_1_FirstOutput;      /* '<S29>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete;         /* '<S29>/INPUT_4_1_1' */
  real_T INPUT_4_1_1_FirstOutput;      /* '<S29>/INPUT_4_1_1' */
  real_T INPUT_23_1_1_Discrete;        /* '<S29>/INPUT_23_1_1' */
  real_T INPUT_23_1_1_FirstOutput;     /* '<S29>/INPUT_23_1_1' */
  real_T INPUT_21_1_1_Discrete;        /* '<S29>/INPUT_21_1_1' */
  real_T INPUT_21_1_1_FirstOutput;     /* '<S29>/INPUT_21_1_1' */
  real_T INPUT_22_1_1_Discrete;        /* '<S29>/INPUT_22_1_1' */
  real_T INPUT_22_1_1_FirstOutput;     /* '<S29>/INPUT_22_1_1' */
  real_T INPUT_24_1_1_Discrete;        /* '<S29>/INPUT_24_1_1' */
  real_T INPUT_24_1_1_FirstOutput;     /* '<S29>/INPUT_24_1_1' */
  real_T INPUT_27_1_1_Discrete;        /* '<S29>/INPUT_27_1_1' */
  real_T INPUT_27_1_1_FirstOutput;     /* '<S29>/INPUT_27_1_1' */
  real_T INPUT_25_1_1_Discrete;        /* '<S29>/INPUT_25_1_1' */
  real_T INPUT_25_1_1_FirstOutput;     /* '<S29>/INPUT_25_1_1' */
  real_T INPUT_26_1_1_Discrete;        /* '<S29>/INPUT_26_1_1' */
  real_T INPUT_26_1_1_FirstOutput;     /* '<S29>/INPUT_26_1_1' */
  real_T INPUT_28_1_1_Discrete;        /* '<S29>/INPUT_28_1_1' */
  real_T INPUT_28_1_1_FirstOutput;     /* '<S29>/INPUT_28_1_1' */
  real_T INPUT_31_1_1_Discrete;        /* '<S29>/INPUT_31_1_1' */
  real_T INPUT_31_1_1_FirstOutput;     /* '<S29>/INPUT_31_1_1' */
  real_T INPUT_29_1_1_Discrete;        /* '<S29>/INPUT_29_1_1' */
  real_T INPUT_29_1_1_FirstOutput;     /* '<S29>/INPUT_29_1_1' */
  real_T INPUT_30_1_1_Discrete;        /* '<S29>/INPUT_30_1_1' */
  real_T INPUT_30_1_1_FirstOutput;     /* '<S29>/INPUT_30_1_1' */
  real_T INPUT_32_1_1_Discrete;        /* '<S29>/INPUT_32_1_1' */
  real_T INPUT_32_1_1_FirstOutput;     /* '<S29>/INPUT_32_1_1' */
  real_T INPUT_35_1_1_Discrete;        /* '<S29>/INPUT_35_1_1' */
  real_T INPUT_35_1_1_FirstOutput;     /* '<S29>/INPUT_35_1_1' */
  real_T INPUT_33_1_1_Discrete;        /* '<S29>/INPUT_33_1_1' */
  real_T INPUT_33_1_1_FirstOutput;     /* '<S29>/INPUT_33_1_1' */
  real_T INPUT_34_1_1_Discrete;        /* '<S29>/INPUT_34_1_1' */
  real_T INPUT_34_1_1_FirstOutput;     /* '<S29>/INPUT_34_1_1' */
  real_T INPUT_36_1_1_Discrete;        /* '<S29>/INPUT_36_1_1' */
  real_T INPUT_36_1_1_FirstOutput;     /* '<S29>/INPUT_36_1_1' */
  real_T INPUT_8_1_1_Discrete[2];      /* '<S29>/INPUT_8_1_1' */
  real_T INPUT_8_1_2_Discrete[2];      /* '<S29>/INPUT_8_1_2' */
  real_T INPUT_8_1_3_Discrete[2];      /* '<S29>/INPUT_8_1_3' */
  real_T INPUT_7_1_1_Discrete[2];      /* '<S29>/INPUT_7_1_1' */
  real_T INPUT_7_1_2_Discrete[2];      /* '<S29>/INPUT_7_1_2' */
  real_T INPUT_7_1_3_Discrete[2];      /* '<S29>/INPUT_7_1_3' */
  real_T INPUT_5_1_1_Discrete[2];      /* '<S29>/INPUT_5_1_1' */
  real_T INPUT_5_1_2_Discrete[2];      /* '<S29>/INPUT_5_1_2' */
  real_T INPUT_5_1_3_Discrete[2];      /* '<S29>/INPUT_5_1_3' */
  real_T INPUT_6_1_1_Discrete[2];      /* '<S29>/INPUT_6_1_1' */
  real_T INPUT_6_1_2_Discrete[2];      /* '<S29>/INPUT_6_1_2' */
  real_T INPUT_6_1_3_Discrete[2];      /* '<S29>/INPUT_6_1_3' */
  real_T INPUT_12_1_1_Discrete[2];     /* '<S29>/INPUT_12_1_1' */
  real_T INPUT_12_1_2_Discrete[2];     /* '<S29>/INPUT_12_1_2' */
  real_T INPUT_12_1_3_Discrete[2];     /* '<S29>/INPUT_12_1_3' */
  real_T INPUT_11_1_1_Discrete[2];     /* '<S29>/INPUT_11_1_1' */
  real_T INPUT_11_1_2_Discrete[2];     /* '<S29>/INPUT_11_1_2' */
  real_T INPUT_11_1_3_Discrete[2];     /* '<S29>/INPUT_11_1_3' */
  real_T INPUT_9_1_1_Discrete[2];      /* '<S29>/INPUT_9_1_1' */
  real_T INPUT_9_1_2_Discrete[2];      /* '<S29>/INPUT_9_1_2' */
  real_T INPUT_9_1_3_Discrete[2];      /* '<S29>/INPUT_9_1_3' */
  real_T INPUT_10_1_1_Discrete[2];     /* '<S29>/INPUT_10_1_1' */
  real_T INPUT_10_1_2_Discrete[2];     /* '<S29>/INPUT_10_1_2' */
  real_T INPUT_10_1_3_Discrete[2];     /* '<S29>/INPUT_10_1_3' */
  real_T INPUT_16_1_1_Discrete[2];     /* '<S29>/INPUT_16_1_1' */
  real_T INPUT_16_1_2_Discrete[2];     /* '<S29>/INPUT_16_1_2' */
  real_T INPUT_16_1_3_Discrete[2];     /* '<S29>/INPUT_16_1_3' */
  real_T INPUT_15_1_1_Discrete[2];     /* '<S29>/INPUT_15_1_1' */
  real_T INPUT_15_1_2_Discrete[2];     /* '<S29>/INPUT_15_1_2' */
  real_T INPUT_15_1_3_Discrete[2];     /* '<S29>/INPUT_15_1_3' */
  real_T INPUT_13_1_1_Discrete[2];     /* '<S29>/INPUT_13_1_1' */
  real_T INPUT_13_1_2_Discrete[2];     /* '<S29>/INPUT_13_1_2' */
  real_T INPUT_13_1_3_Discrete[2];     /* '<S29>/INPUT_13_1_3' */
  real_T INPUT_14_1_1_Discrete[2];     /* '<S29>/INPUT_14_1_1' */
  real_T INPUT_14_1_2_Discrete[2];     /* '<S29>/INPUT_14_1_2' */
  real_T INPUT_14_1_3_Discrete[2];     /* '<S29>/INPUT_14_1_3' */
  real_T INPUT_20_1_1_Discrete[2];     /* '<S29>/INPUT_20_1_1' */
  real_T INPUT_20_1_2_Discrete[2];     /* '<S29>/INPUT_20_1_2' */
  real_T INPUT_20_1_3_Discrete[2];     /* '<S29>/INPUT_20_1_3' */
  real_T INPUT_19_1_1_Discrete[2];     /* '<S29>/INPUT_19_1_1' */
  real_T INPUT_19_1_2_Discrete[2];     /* '<S29>/INPUT_19_1_2' */
  real_T INPUT_19_1_3_Discrete[2];     /* '<S29>/INPUT_19_1_3' */
  real_T INPUT_17_1_1_Discrete[2];     /* '<S29>/INPUT_17_1_1' */
  real_T INPUT_17_1_2_Discrete[2];     /* '<S29>/INPUT_17_1_2' */
  real_T INPUT_17_1_3_Discrete[2];     /* '<S29>/INPUT_17_1_3' */
  real_T INPUT_18_1_1_Discrete[2];     /* '<S29>/INPUT_18_1_1' */
  real_T INPUT_18_1_2_Discrete[2];     /* '<S29>/INPUT_18_1_2' */
  real_T INPUT_18_1_3_Discrete[2];     /* '<S29>/INPUT_18_1_3' */
  real_T STATE_1_Discrete;             /* '<S29>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S29>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S29>/STATE_1' */
  void* STATE_1_SimData;               /* '<S29>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S29>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S29>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S29>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S29>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S29>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S29>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S29>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S29>/OUTPUT_1_0' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  int_T STATE_1_Modes;                 /* '<S29>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S29>/OUTPUT_1_0' */
  int8_T If1_ActiveSubsystem;          /* '<S12>/If1' */
  int8_T If1_ActiveSubsystem_p;        /* '<S13>/If1' */
  int8_T If1_ActiveSubsystem_e;        /* '<S14>/If1' */
  int8_T If1_ActiveSubsystem_a;        /* '<S15>/If1' */
  boolean_T STATE_1_FirstOutput;       /* '<S29>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S29>/OUTPUT_1_0' */
} DW_robot_simple_balancing_T;

/* Continuous states (default storage) */
typedef struct {
  real_T robot_simple_balancingSPConv6ou[2];/* '<S29>/INPUT_1_1_1' */
  real_T robot_simple_balancingSPConv7ou[2];/* '<S29>/INPUT_2_1_1' */
  real_T robot_simple_balancingSPConv8ou[2];/* '<S29>/INPUT_3_1_1' */
  real_T robot_simple_balancingSimulink_[2];/* '<S29>/INPUT_4_1_1' */
  real_T robot_simple_balancingSubsystem[2];/* '<S29>/INPUT_23_1_1' */
  real_T robot_simple_balancingSubsyst_m[2];/* '<S29>/INPUT_21_1_1' */
  real_T robot_simple_balancingSubsyst_o[2];/* '<S29>/INPUT_22_1_1' */
  real_T robot_simple_balancingSubsyst_i[2];/* '<S29>/INPUT_24_1_1' */
  real_T robot_simple_balancingSubsyst_d[2];/* '<S29>/INPUT_27_1_1' */
  real_T robot_simple_balancingSubsys_ie[2];/* '<S29>/INPUT_25_1_1' */
  real_T robot_simple_balancingSubsyst_e[2];/* '<S29>/INPUT_26_1_1' */
  real_T robot_simple_balancingSubsyst_f[2];/* '<S29>/INPUT_28_1_1' */
  real_T robot_simple_balancingSubsyst_j[2];/* '<S29>/INPUT_31_1_1' */
  real_T robot_simple_balancingSubsyst_k[2];/* '<S29>/INPUT_29_1_1' */
  real_T robot_simple_balancingSubsys_jm[2];/* '<S29>/INPUT_30_1_1' */
  real_T robot_simple_balancingSubsyst_a[2];/* '<S29>/INPUT_32_1_1' */
  real_T robot_simple_balancingSubsys_ma[2];/* '<S29>/INPUT_35_1_1' */
  real_T robot_simple_balancingSubsyst_l[2];/* '<S29>/INPUT_33_1_1' */
  real_T robot_simple_balancingSubsys_mm[2];/* '<S29>/INPUT_34_1_1' */
  real_T robot_simple_balancingSubsyst_p[2];/* '<S29>/INPUT_36_1_1' */
  real_T robot_simple_balancingx6_DOF_Jo[13];/* '<S29>/STATE_1' */
} X_robot_simple_balancing_T;

/* State derivatives (default storage) */
typedef struct {
  real_T robot_simple_balancingSPConv6ou[2];/* '<S29>/INPUT_1_1_1' */
  real_T robot_simple_balancingSPConv7ou[2];/* '<S29>/INPUT_2_1_1' */
  real_T robot_simple_balancingSPConv8ou[2];/* '<S29>/INPUT_3_1_1' */
  real_T robot_simple_balancingSimulink_[2];/* '<S29>/INPUT_4_1_1' */
  real_T robot_simple_balancingSubsystem[2];/* '<S29>/INPUT_23_1_1' */
  real_T robot_simple_balancingSubsyst_m[2];/* '<S29>/INPUT_21_1_1' */
  real_T robot_simple_balancingSubsyst_o[2];/* '<S29>/INPUT_22_1_1' */
  real_T robot_simple_balancingSubsyst_i[2];/* '<S29>/INPUT_24_1_1' */
  real_T robot_simple_balancingSubsyst_d[2];/* '<S29>/INPUT_27_1_1' */
  real_T robot_simple_balancingSubsys_ie[2];/* '<S29>/INPUT_25_1_1' */
  real_T robot_simple_balancingSubsyst_e[2];/* '<S29>/INPUT_26_1_1' */
  real_T robot_simple_balancingSubsyst_f[2];/* '<S29>/INPUT_28_1_1' */
  real_T robot_simple_balancingSubsyst_j[2];/* '<S29>/INPUT_31_1_1' */
  real_T robot_simple_balancingSubsyst_k[2];/* '<S29>/INPUT_29_1_1' */
  real_T robot_simple_balancingSubsys_jm[2];/* '<S29>/INPUT_30_1_1' */
  real_T robot_simple_balancingSubsyst_a[2];/* '<S29>/INPUT_32_1_1' */
  real_T robot_simple_balancingSubsys_ma[2];/* '<S29>/INPUT_35_1_1' */
  real_T robot_simple_balancingSubsyst_l[2];/* '<S29>/INPUT_33_1_1' */
  real_T robot_simple_balancingSubsys_mm[2];/* '<S29>/INPUT_34_1_1' */
  real_T robot_simple_balancingSubsyst_p[2];/* '<S29>/INPUT_36_1_1' */
  real_T robot_simple_balancingx6_DOF_Jo[13];/* '<S29>/STATE_1' */
} XDot_robot_simple_balancing_T;

/* State disabled  */
typedef struct {
  boolean_T robot_simple_balancingSPConv6ou[2];/* '<S29>/INPUT_1_1_1' */
  boolean_T robot_simple_balancingSPConv7ou[2];/* '<S29>/INPUT_2_1_1' */
  boolean_T robot_simple_balancingSPConv8ou[2];/* '<S29>/INPUT_3_1_1' */
  boolean_T robot_simple_balancingSimulink_[2];/* '<S29>/INPUT_4_1_1' */
  boolean_T robot_simple_balancingSubsystem[2];/* '<S29>/INPUT_23_1_1' */
  boolean_T robot_simple_balancingSubsyst_m[2];/* '<S29>/INPUT_21_1_1' */
  boolean_T robot_simple_balancingSubsyst_o[2];/* '<S29>/INPUT_22_1_1' */
  boolean_T robot_simple_balancingSubsyst_i[2];/* '<S29>/INPUT_24_1_1' */
  boolean_T robot_simple_balancingSubsyst_d[2];/* '<S29>/INPUT_27_1_1' */
  boolean_T robot_simple_balancingSubsys_ie[2];/* '<S29>/INPUT_25_1_1' */
  boolean_T robot_simple_balancingSubsyst_e[2];/* '<S29>/INPUT_26_1_1' */
  boolean_T robot_simple_balancingSubsyst_f[2];/* '<S29>/INPUT_28_1_1' */
  boolean_T robot_simple_balancingSubsyst_j[2];/* '<S29>/INPUT_31_1_1' */
  boolean_T robot_simple_balancingSubsyst_k[2];/* '<S29>/INPUT_29_1_1' */
  boolean_T robot_simple_balancingSubsys_jm[2];/* '<S29>/INPUT_30_1_1' */
  boolean_T robot_simple_balancingSubsyst_a[2];/* '<S29>/INPUT_32_1_1' */
  boolean_T robot_simple_balancingSubsys_ma[2];/* '<S29>/INPUT_35_1_1' */
  boolean_T robot_simple_balancingSubsyst_l[2];/* '<S29>/INPUT_33_1_1' */
  boolean_T robot_simple_balancingSubsys_mm[2];/* '<S29>/INPUT_34_1_1' */
  boolean_T robot_simple_balancingSubsyst_p[2];/* '<S29>/INPUT_36_1_1' */
  boolean_T robot_simple_balancingx6_DOF_Jo[13];/* '<S29>/STATE_1' */
} XDis_robot_simple_balancing_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_robot_simple_balancing_T_ {
  real_T c_b;                          /* Variable: c_b
                                        * Referenced by:
                                        *   '<S55>/Gain2'
                                        *   '<S99>/Gain2'
                                        *   '<S143>/Gain2'
                                        *   '<S187>/Gain2'
                                        */
  real_T c_k;                          /* Variable: c_k
                                        * Referenced by:
                                        *   '<S55>/Gain1'
                                        *   '<S99>/Gain1'
                                        *   '<S143>/Gain1'
                                        *   '<S187>/Gain1'
                                        */
  real_T desired_q[16];                /* Variable: desired_q
                                        * Referenced by: '<Root>/desired_q '
                                        */
  real_T SpheretoPlaneForceFR_plane_dept;
                              /* Mask Parameter: SpheretoPlaneForceFR_plane_dept
                               * Referenced by: '<S46>/Constant'
                               */
  real_T SpheretoPlaneForceFR1_plane_dep;
                              /* Mask Parameter: SpheretoPlaneForceFR1_plane_dep
                               * Referenced by: '<S90>/Constant'
                               */
  real_T SpheretoPlaneForceFR2_plane_dep;
                              /* Mask Parameter: SpheretoPlaneForceFR2_plane_dep
                               * Referenced by: '<S134>/Constant'
                               */
  real_T SpheretoPlaneForceFR3_plane_dep;
                              /* Mask Parameter: SpheretoPlaneForceFR3_plane_dep
                               * Referenced by: '<S178>/Constant'
                               */
  real_T SpheretoPlaneForceFR_plane_lenx;
                              /* Mask Parameter: SpheretoPlaneForceFR_plane_lenx
                               * Referenced by: '<S36>/Constant'
                               */
  real_T SpheretoPlaneForceFR1_plane_len;
                              /* Mask Parameter: SpheretoPlaneForceFR1_plane_len
                               * Referenced by: '<S80>/Constant'
                               */
  real_T SpheretoPlaneForceFR2_plane_len;
                              /* Mask Parameter: SpheretoPlaneForceFR2_plane_len
                               * Referenced by: '<S124>/Constant'
                               */
  real_T SpheretoPlaneForceFR3_plane_len;
                              /* Mask Parameter: SpheretoPlaneForceFR3_plane_len
                               * Referenced by: '<S168>/Constant'
                               */
  real_T SpheretoPlaneForceFR_plane_leny;
                              /* Mask Parameter: SpheretoPlaneForceFR_plane_leny
                               * Referenced by: '<S37>/Constant'
                               */
  real_T SpheretoPlaneForceFR1_plane_l_j;
                              /* Mask Parameter: SpheretoPlaneForceFR1_plane_l_j
                               * Referenced by: '<S81>/Constant'
                               */
  real_T SpheretoPlaneForceFR2_plane_l_g;
                              /* Mask Parameter: SpheretoPlaneForceFR2_plane_l_g
                               * Referenced by: '<S125>/Constant'
                               */
  real_T SpheretoPlaneForceFR3_plane_l_e;
                              /* Mask Parameter: SpheretoPlaneForceFR3_plane_l_e
                               * Referenced by: '<S169>/Constant'
                               */
  real_T SpheretoPlaneForceFR_sphere_rad;
                              /* Mask Parameter: SpheretoPlaneForceFR_sphere_rad
                               * Referenced by:
                               *   '<S46>/Constant'
                               *   '<S53>/Fx1'
                               */
  real_T SpheretoPlaneForceFR1_sphere_ra;
                              /* Mask Parameter: SpheretoPlaneForceFR1_sphere_ra
                               * Referenced by:
                               *   '<S90>/Constant'
                               *   '<S97>/Fx1'
                               */
  real_T SpheretoPlaneForceFR2_sphere_ra;
                              /* Mask Parameter: SpheretoPlaneForceFR2_sphere_ra
                               * Referenced by:
                               *   '<S134>/Constant'
                               *   '<S141>/Fx1'
                               */
  real_T SpheretoPlaneForceFR3_sphere_ra;
                              /* Mask Parameter: SpheretoPlaneForceFR3_sphere_ra
                               * Referenced by:
                               *   '<S178>/Constant'
                               *   '<S185>/Fx1'
                               */
  struct_CVxZLPMsKyaISSiaEWoII Out_Y0; /* Computed Parameter: Out_Y0
                                        * Referenced by: '<S33>/Out'
                                        */
  struct_CVxZLPMsKyaISSiaEWoII Out_Y0_o;/* Computed Parameter: Out_Y0_o
                                         * Referenced by: '<S77>/Out'
                                         */
  struct_CVxZLPMsKyaISSiaEWoII Out_Y0_k;/* Computed Parameter: Out_Y0_k
                                         * Referenced by: '<S121>/Out'
                                         */
  struct_CVxZLPMsKyaISSiaEWoII Out_Y0_m;/* Computed Parameter: Out_Y0_m
                                         * Referenced by: '<S165>/Out'
                                         */
  real_T DeadZone_Start;               /* Expression: -inf
                                        * Referenced by: '<S46>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: 0
                                        * Referenced by: '<S46>/Dead Zone'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S46>/Gain2'
                                        */
  real_T Fx_Value;                     /* Expression: 0
                                        * Referenced by: '<S49>/Fx'
                                        */
  real_T Saturation_UpperSat;          /* Expression: Inf
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T CoefficientofFrictionvsVelocity[6];
                                    /* Expression: [-muk -muk -mus mus  muk muk]
                                     * Referenced by: '<S54>/Coefficient of Friction vs Velocity'
                                     */
  real_T CoefficientofFrictionvsVeloci_h[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S54>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S54>/Gain2'
                                        */
  real_T Fx1_Value;                    /* Expression: 0
                                        * Referenced by: '<S48>/Fx1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T Fx2_Value[3];                 /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S48>/Fx2'
                                        */
  real_T Zeros_Value[12];              /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S34>/Zeros'
                                        */
  real_T DeadZone_Start_i;             /* Expression: -inf
                                        * Referenced by: '<S90>/Dead Zone'
                                        */
  real_T DeadZone_End_j;               /* Expression: 0
                                        * Referenced by: '<S90>/Dead Zone'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S90>/Gain2'
                                        */
  real_T Fx_Value_a;                   /* Expression: 0
                                        * Referenced by: '<S93>/Fx'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: Inf
                                        * Referenced by: '<S99>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 0
                                        * Referenced by: '<S99>/Saturation'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S93>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_g[6];
                                    /* Expression: [-muk -muk -mus mus  muk muk]
                                     * Referenced by: '<S98>/Coefficient of Friction vs Velocity'
                                     */
  real_T CoefficientofFrictionvsVeloci_f[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S98>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain2'
                                        */
  real_T Fx1_Value_d;                  /* Expression: 0
                                        * Referenced by: '<S92>/Fx1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S92>/Gain'
                                        */
  real_T Fx2_Value_e[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S92>/Fx2'
                                        */
  real_T Zeros_Value_k[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S78>/Zeros'
                                        */
  real_T DeadZone_Start_e;             /* Expression: -inf
                                        * Referenced by: '<S134>/Dead Zone'
                                        */
  real_T DeadZone_End_p;               /* Expression: 0
                                        * Referenced by: '<S134>/Dead Zone'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S134>/Gain2'
                                        */
  real_T Fx_Value_d;                   /* Expression: 0
                                        * Referenced by: '<S137>/Fx'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: Inf
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: 0
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S137>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_n[6];
                                    /* Expression: [-muk -muk -mus mus  muk muk]
                                     * Referenced by: '<S142>/Coefficient of Friction vs Velocity'
                                     */
  real_T CoefficientofFrictionvsVeloci_m[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S142>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S142>/Gain2'
                                        */
  real_T Fx1_Value_k;                  /* Expression: 0
                                        * Referenced by: '<S136>/Fx1'
                                        */
  real_T Gain_Gain_d1;                 /* Expression: -1
                                        * Referenced by: '<S136>/Gain'
                                        */
  real_T Fx2_Value_m[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S136>/Fx2'
                                        */
  real_T Zeros_Value_m[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S122>/Zeros'
                                        */
  real_T DeadZone_Start_f;             /* Expression: -inf
                                        * Referenced by: '<S178>/Dead Zone'
                                        */
  real_T DeadZone_End_ps;              /* Expression: 0
                                        * Referenced by: '<S178>/Dead Zone'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S178>/Gain2'
                                        */
  real_T Fx_Value_c;                   /* Expression: 0
                                        * Referenced by: '<S181>/Fx'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: Inf
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T Saturation_LowerSat_op;       /* Expression: 0
                                        * Referenced by: '<S187>/Saturation'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S181>/Gain'
                                        */
  real_T CoefficientofFrictionvsVeloci_e[6];
                                    /* Expression: [-muk -muk -mus mus  muk muk]
                                     * Referenced by: '<S186>/Coefficient of Friction vs Velocity'
                                     */
  real_T CoefficientofFrictionvsVeloc_my[6];/* Expression: [-3 -1.5 -1 1 1.5 3]*vth
                                             * Referenced by: '<S186>/Coefficient of Friction vs Velocity'
                                             */
  real_T Gain2_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S186>/Gain2'
                                        */
  real_T Fx1_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S180>/Fx1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S180>/Gain'
                                        */
  real_T Fx2_Value_j[3];               /* Expression: [0 0 -sphere_rad]
                                        * Referenced by: '<S180>/Fx2'
                                        */
  real_T Zeros_Value_f[12];            /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S166>/Zeros'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Constant_Value[3];            /* Expression: [0.3;0.2;0.6]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Step1_Time;                   /* Expression: 1.9
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 5*pi/180
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: -2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Gain_Gain_mp;                 /* Expression: 2
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S12>/Merge'
                                       */
  real_T Gain_Gain_a;                  /* Expression: 2
                                        * Referenced by: '<S74>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real_T Merge_InitialOutput_o;     /* Computed Parameter: Merge_InitialOutput_o
                                     * Referenced by: '<S13>/Merge'
                                     */
  real_T Gain_Gain_ln;                 /* Expression: 2
                                        * Referenced by: '<S118>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S118>/Gain1'
                                        */
  real_T Merge_InitialOutput_d;     /* Computed Parameter: Merge_InitialOutput_d
                                     * Referenced by: '<S14>/Merge'
                                     */
  real_T Gain_Gain_h;                  /* Expression: 2
                                        * Referenced by: '<S162>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S162>/Gain1'
                                        */
  real_T Merge_InitialOutput_h;     /* Computed Parameter: Merge_InitialOutput_h
                                     * Referenced by: '<S15>/Merge'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_robot_simple_balancin_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_robot_simple_balancing_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[53];
  real_T odeF[4][53];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_robot_simple_balancing_T robot_simple_balancing_P;

/* Block signals (default storage) */
extern B_robot_simple_balancing_T robot_simple_balancing_B;

/* Continuous states (default storage) */
extern X_robot_simple_balancing_T robot_simple_balancing_X;

/* Block states (default storage) */
extern DW_robot_simple_balancing_T robot_simple_balancing_DW;

/* Model entry point functions */
extern void robot_simple_balancing_initialize(void);
extern void robot_simple_balancing_step(void);
extern void robot_simple_balancing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_robot_simple_balanci_T *const robot_simple_balancing_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'robot_simple_balancing'
 * '<S1>'   : 'robot_simple_balancing/MATLAB Function1'
 * '<S2>'   : 'robot_simple_balancing/PS-Simulink Converter'
 * '<S3>'   : 'robot_simple_balancing/PS-Simulink Converter1'
 * '<S4>'   : 'robot_simple_balancing/PS-Simulink Converter2'
 * '<S5>'   : 'robot_simple_balancing/PS-Simulink Converter3'
 * '<S6>'   : 'robot_simple_balancing/PS-Simulink Converter4'
 * '<S7>'   : 'robot_simple_balancing/SPConv6'
 * '<S8>'   : 'robot_simple_balancing/SPConv7'
 * '<S9>'   : 'robot_simple_balancing/SPConv8'
 * '<S10>'  : 'robot_simple_balancing/Simulink-PS Converter3'
 * '<S11>'  : 'robot_simple_balancing/Solver Configuration'
 * '<S12>'  : 'robot_simple_balancing/Sphere to Plane Force FR'
 * '<S13>'  : 'robot_simple_balancing/Sphere to Plane Force FR1'
 * '<S14>'  : 'robot_simple_balancing/Sphere to Plane Force FR2'
 * '<S15>'  : 'robot_simple_balancing/Sphere to Plane Force FR3'
 * '<S16>'  : 'robot_simple_balancing/Subsystem'
 * '<S17>'  : 'robot_simple_balancing/Subsystem1'
 * '<S18>'  : 'robot_simple_balancing/Subsystem2'
 * '<S19>'  : 'robot_simple_balancing/Subsystem3'
 * '<S20>'  : 'robot_simple_balancing/PS-Simulink Converter/EVAL_KEY'
 * '<S21>'  : 'robot_simple_balancing/PS-Simulink Converter1/EVAL_KEY'
 * '<S22>'  : 'robot_simple_balancing/PS-Simulink Converter2/EVAL_KEY'
 * '<S23>'  : 'robot_simple_balancing/PS-Simulink Converter3/EVAL_KEY'
 * '<S24>'  : 'robot_simple_balancing/PS-Simulink Converter4/EVAL_KEY'
 * '<S25>'  : 'robot_simple_balancing/SPConv6/EVAL_KEY'
 * '<S26>'  : 'robot_simple_balancing/SPConv7/EVAL_KEY'
 * '<S27>'  : 'robot_simple_balancing/SPConv8/EVAL_KEY'
 * '<S28>'  : 'robot_simple_balancing/Simulink-PS Converter3/EVAL_KEY'
 * '<S29>'  : 'robot_simple_balancing/Solver Configuration/EVAL_KEY'
 * '<S30>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Check Sphere on Plane'
 * '<S31>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux'
 * '<S32>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Enable Outputs'
 * '<S33>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces'
 * '<S34>'  : 'robot_simple_balancing/Sphere to Plane Force FR/No Force'
 * '<S35>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing'
 * '<S36>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Check Sphere on Plane/Check loc x-axis'
 * '<S37>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Check Sphere on Plane/Check loc y-axis'
 * '<S38>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter'
 * '<S39>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter1'
 * '<S40>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter2'
 * '<S41>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter6'
 * '<S42>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S43>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S44>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S45>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S46>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Calculate Penetration'
 * '<S47>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Cross Product'
 * '<S48>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Ff'
 * '<S49>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Fn'
 * '<S50>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Force Law'
 * '<S51>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Ff/Cross Product'
 * '<S52>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Ff/Friction Law'
 * '<S53>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Ff/SlipVel'
 * '<S54>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S55>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Forces/Force Law/Linear'
 * '<S56>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter'
 * '<S57>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter1'
 * '<S58>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter2'
 * '<S59>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter3'
 * '<S60>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter4'
 * '<S61>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter5'
 * '<S62>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter6'
 * '<S63>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter7'
 * '<S64>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter8'
 * '<S65>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S66>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S67>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S68>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S69>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S70>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S71>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S72>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S73>'  : 'robot_simple_balancing/Sphere to Plane Force FR/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S74>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Check Sphere on Plane'
 * '<S75>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux'
 * '<S76>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Enable Outputs'
 * '<S77>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces'
 * '<S78>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/No Force'
 * '<S79>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing'
 * '<S80>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Check Sphere on Plane/Check loc x-axis'
 * '<S81>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Check Sphere on Plane/Check loc y-axis'
 * '<S82>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter'
 * '<S83>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter1'
 * '<S84>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter2'
 * '<S85>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter6'
 * '<S86>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S87>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S88>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S89>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S90>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Calculate Penetration'
 * '<S91>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Cross Product'
 * '<S92>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Ff'
 * '<S93>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Fn'
 * '<S94>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Force Law'
 * '<S95>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Ff/Cross Product'
 * '<S96>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Ff/Friction Law'
 * '<S97>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Ff/SlipVel'
 * '<S98>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S99>'  : 'robot_simple_balancing/Sphere to Plane Force FR1/Forces/Force Law/Linear'
 * '<S100>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter'
 * '<S101>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter1'
 * '<S102>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter2'
 * '<S103>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter3'
 * '<S104>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter4'
 * '<S105>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter5'
 * '<S106>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter6'
 * '<S107>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter7'
 * '<S108>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter8'
 * '<S109>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S110>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S111>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S112>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S113>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S114>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S115>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S116>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S117>' : 'robot_simple_balancing/Sphere to Plane Force FR1/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S118>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Check Sphere on Plane'
 * '<S119>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux'
 * '<S120>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Enable Outputs'
 * '<S121>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces'
 * '<S122>' : 'robot_simple_balancing/Sphere to Plane Force FR2/No Force'
 * '<S123>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing'
 * '<S124>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Check Sphere on Plane/Check loc x-axis'
 * '<S125>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Check Sphere on Plane/Check loc y-axis'
 * '<S126>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter'
 * '<S127>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter1'
 * '<S128>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter2'
 * '<S129>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter6'
 * '<S130>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S131>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S132>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S133>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S134>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Calculate Penetration'
 * '<S135>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Cross Product'
 * '<S136>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Ff'
 * '<S137>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Fn'
 * '<S138>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Force Law'
 * '<S139>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Ff/Cross Product'
 * '<S140>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Ff/Friction Law'
 * '<S141>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Ff/SlipVel'
 * '<S142>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S143>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Forces/Force Law/Linear'
 * '<S144>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter'
 * '<S145>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter1'
 * '<S146>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter2'
 * '<S147>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter3'
 * '<S148>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter4'
 * '<S149>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter5'
 * '<S150>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter6'
 * '<S151>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter7'
 * '<S152>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter8'
 * '<S153>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S154>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S155>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S156>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S157>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S158>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S159>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S160>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S161>' : 'robot_simple_balancing/Sphere to Plane Force FR2/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S162>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Check Sphere on Plane'
 * '<S163>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux'
 * '<S164>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Enable Outputs'
 * '<S165>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces'
 * '<S166>' : 'robot_simple_balancing/Sphere to Plane Force FR3/No Force'
 * '<S167>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing'
 * '<S168>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Check Sphere on Plane/Check loc x-axis'
 * '<S169>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Check Sphere on Plane/Check loc y-axis'
 * '<S170>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter'
 * '<S171>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter1'
 * '<S172>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter2'
 * '<S173>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter6'
 * '<S174>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter/EVAL_KEY'
 * '<S175>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter1/EVAL_KEY'
 * '<S176>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter2/EVAL_KEY'
 * '<S177>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Demux/Simulink-PS Converter6/EVAL_KEY'
 * '<S178>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Calculate Penetration'
 * '<S179>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Cross Product'
 * '<S180>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Ff'
 * '<S181>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Fn'
 * '<S182>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Force Law'
 * '<S183>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Ff/Cross Product'
 * '<S184>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Ff/Friction Law'
 * '<S185>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Ff/SlipVel'
 * '<S186>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Ff/Friction Law/Stick-Slip C '
 * '<S187>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Forces/Force Law/Linear'
 * '<S188>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter'
 * '<S189>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter1'
 * '<S190>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter2'
 * '<S191>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter3'
 * '<S192>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter4'
 * '<S193>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter5'
 * '<S194>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter6'
 * '<S195>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter7'
 * '<S196>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter8'
 * '<S197>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter/EVAL_KEY'
 * '<S198>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter1/EVAL_KEY'
 * '<S199>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter2/EVAL_KEY'
 * '<S200>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter3/EVAL_KEY'
 * '<S201>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter4/EVAL_KEY'
 * '<S202>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter5/EVAL_KEY'
 * '<S203>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter6/EVAL_KEY'
 * '<S204>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter7/EVAL_KEY'
 * '<S205>' : 'robot_simple_balancing/Sphere to Plane Force FR3/Sensing/PS-Simulink Converter8/EVAL_KEY'
 * '<S206>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter1'
 * '<S207>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter2'
 * '<S208>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter3'
 * '<S209>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter4'
 * '<S210>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter1/EVAL_KEY'
 * '<S211>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter2/EVAL_KEY'
 * '<S212>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter3/EVAL_KEY'
 * '<S213>' : 'robot_simple_balancing/Subsystem/Simulink-PS Converter4/EVAL_KEY'
 * '<S214>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter1'
 * '<S215>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter2'
 * '<S216>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter3'
 * '<S217>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter4'
 * '<S218>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter1/EVAL_KEY'
 * '<S219>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter2/EVAL_KEY'
 * '<S220>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter3/EVAL_KEY'
 * '<S221>' : 'robot_simple_balancing/Subsystem1/Simulink-PS Converter4/EVAL_KEY'
 * '<S222>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter1'
 * '<S223>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter2'
 * '<S224>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter3'
 * '<S225>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter4'
 * '<S226>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter1/EVAL_KEY'
 * '<S227>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter2/EVAL_KEY'
 * '<S228>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter3/EVAL_KEY'
 * '<S229>' : 'robot_simple_balancing/Subsystem2/Simulink-PS Converter4/EVAL_KEY'
 * '<S230>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter1'
 * '<S231>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter2'
 * '<S232>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter3'
 * '<S233>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter4'
 * '<S234>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter1/EVAL_KEY'
 * '<S235>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter2/EVAL_KEY'
 * '<S236>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter3/EVAL_KEY'
 * '<S237>' : 'robot_simple_balancing/Subsystem3/Simulink-PS Converter4/EVAL_KEY'
 */
#endif                                /* RTW_HEADER_robot_simple_balancing_h_ */
