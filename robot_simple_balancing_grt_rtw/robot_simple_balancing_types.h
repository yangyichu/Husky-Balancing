/*
 * robot_simple_balancing_types.h
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

#ifndef RTW_HEADER_robot_simple_balancing_types_h_
#define RTW_HEADER_robot_simple_balancing_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_CVxZLPMsKyaISSiaEWoII_
#define DEFINED_TYPEDEF_FOR_struct_CVxZLPMsKyaISSiaEWoII_

typedef struct {
  real_T Penetration;
  real_T Penetration_Vel;
  real_T Spr_Force;
  real_T Damp_Force;
  real_T Normal_Force;
  real_T Friction_Force[3];
} struct_CVxZLPMsKyaISSiaEWoII;

#endif

/* Parameters (default storage) */
typedef struct P_robot_simple_balancing_T_ P_robot_simple_balancing_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_robot_simple_balancin_T RT_MODEL_robot_simple_balanci_T;

#endif                          /* RTW_HEADER_robot_simple_balancing_types_h_ */
