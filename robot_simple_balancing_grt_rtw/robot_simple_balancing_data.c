/*
 * robot_simple_balancing_data.c
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

#include "robot_simple_balancing.h"
#include "robot_simple_balancing_private.h"

/* Block parameters (default storage) */
P_robot_simple_balancing_T robot_simple_balancing_P = {
  /* Variable: c_b
   * Referenced by:
   *   '<S55>/Gain2'
   *   '<S99>/Gain2'
   *   '<S143>/Gain2'
   *   '<S187>/Gain2'
   */
  200.0,

  /* Variable: c_k
   * Referenced by:
   *   '<S55>/Gain1'
   *   '<S99>/Gain1'
   *   '<S143>/Gain1'
   *   '<S187>/Gain1'
   */
  5000.0,

  /* Variable: desired_q
   * Referenced by: '<Root>/desired_q '
   */
  { 0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0,
    0.6 },

  /* Mask Parameter: SpheretoPlaneForceFR_plane_dept
   * Referenced by: '<S46>/Constant'
   */
  0.01,

  /* Mask Parameter: SpheretoPlaneForceFR1_plane_dep
   * Referenced by: '<S90>/Constant'
   */
  0.01,

  /* Mask Parameter: SpheretoPlaneForceFR2_plane_dep
   * Referenced by: '<S134>/Constant'
   */
  0.01,

  /* Mask Parameter: SpheretoPlaneForceFR3_plane_dep
   * Referenced by: '<S178>/Constant'
   */
  0.01,

  /* Mask Parameter: SpheretoPlaneForceFR_plane_lenx
   * Referenced by: '<S36>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR1_plane_len
   * Referenced by: '<S80>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR2_plane_len
   * Referenced by: '<S124>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR3_plane_len
   * Referenced by: '<S168>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR_plane_leny
   * Referenced by: '<S37>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR1_plane_l_j
   * Referenced by: '<S81>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR2_plane_l_g
   * Referenced by: '<S125>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR3_plane_l_e
   * Referenced by: '<S169>/Constant'
   */
  5.0,

  /* Mask Parameter: SpheretoPlaneForceFR_sphere_rad
   * Referenced by:
   *   '<S46>/Constant'
   *   '<S53>/Fx1'
   */
  0.04,

  /* Mask Parameter: SpheretoPlaneForceFR1_sphere_ra
   * Referenced by:
   *   '<S90>/Constant'
   *   '<S97>/Fx1'
   */
  0.04,

  /* Mask Parameter: SpheretoPlaneForceFR2_sphere_ra
   * Referenced by:
   *   '<S134>/Constant'
   *   '<S141>/Fx1'
   */
  0.04,

  /* Mask Parameter: SpheretoPlaneForceFR3_sphere_ra
   * Referenced by:
   *   '<S178>/Constant'
   *   '<S185>/Fx1'
   */
  0.04,

  /* Computed Parameter: Out_Y0
   * Referenced by: '<S33>/Out'
   */
  {
    0.0,                               /* Penetration */
    0.0,                               /* Penetration_Vel */
    0.0,                               /* Spr_Force */
    0.0,                               /* Damp_Force */
    0.0,                               /* Normal_Force */

    {
      0.0, 0.0, 0.0 }
    /* Friction_Force */
  },

  /* Computed Parameter: Out_Y0_o
   * Referenced by: '<S77>/Out'
   */
  {
    0.0,                               /* Penetration */
    0.0,                               /* Penetration_Vel */
    0.0,                               /* Spr_Force */
    0.0,                               /* Damp_Force */
    0.0,                               /* Normal_Force */

    {
      0.0, 0.0, 0.0 }
    /* Friction_Force */
  },

  /* Computed Parameter: Out_Y0_k
   * Referenced by: '<S121>/Out'
   */
  {
    0.0,                               /* Penetration */
    0.0,                               /* Penetration_Vel */
    0.0,                               /* Spr_Force */
    0.0,                               /* Damp_Force */
    0.0,                               /* Normal_Force */

    {
      0.0, 0.0, 0.0 }
    /* Friction_Force */
  },

  /* Computed Parameter: Out_Y0_m
   * Referenced by: '<S165>/Out'
   */
  {
    0.0,                               /* Penetration */
    0.0,                               /* Penetration_Vel */
    0.0,                               /* Spr_Force */
    0.0,                               /* Damp_Force */
    0.0,                               /* Normal_Force */

    {
      0.0, 0.0, 0.0 }
    /* Friction_Force */
  },

  /* Expression: -inf
   * Referenced by: '<S46>/Dead Zone'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Dead Zone'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S46>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S49>/Fx'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S55>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S55>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S49>/Gain'
   */
  -1.0,

  /* Expression: [-muk -muk -mus mus  muk muk]
   * Referenced by: '<S54>/Coefficient of Friction vs Velocity'
   */
  { -0.4, -0.4, -0.8, 0.8, 0.4, 0.4 },

  /* Expression: [-3 -1.5 -1 1 1.5 3]*vth
   * Referenced by: '<S54>/Coefficient of Friction vs Velocity'
   */
  { -0.00030000000000000003, -0.00015000000000000001, -0.0001, 0.0001,
    0.00015000000000000001, 0.00030000000000000003 },

  /* Expression: 1
   * Referenced by: '<S54>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S48>/Fx1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S48>/Gain'
   */
  -1.0,

  /* Expression: [0 0 -sphere_rad]
   * Referenced by: '<S48>/Fx2'
   */
  { 0.0, 0.0, -0.04 },

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S34>/Zeros'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -inf
   * Referenced by: '<S90>/Dead Zone'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S90>/Dead Zone'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S90>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S93>/Fx'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S99>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S99>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S93>/Gain'
   */
  -1.0,

  /* Expression: [-muk -muk -mus mus  muk muk]
   * Referenced by: '<S98>/Coefficient of Friction vs Velocity'
   */
  { -0.4, -0.4, -0.8, 0.8, 0.4, 0.4 },

  /* Expression: [-3 -1.5 -1 1 1.5 3]*vth
   * Referenced by: '<S98>/Coefficient of Friction vs Velocity'
   */
  { -0.00030000000000000003, -0.00015000000000000001, -0.0001, 0.0001,
    0.00015000000000000001, 0.00030000000000000003 },

  /* Expression: 1
   * Referenced by: '<S98>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S92>/Fx1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S92>/Gain'
   */
  -1.0,

  /* Expression: [0 0 -sphere_rad]
   * Referenced by: '<S92>/Fx2'
   */
  { 0.0, 0.0, -0.04 },

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S78>/Zeros'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -inf
   * Referenced by: '<S134>/Dead Zone'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S134>/Dead Zone'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S134>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S137>/Fx'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S143>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S143>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S137>/Gain'
   */
  -1.0,

  /* Expression: [-muk -muk -mus mus  muk muk]
   * Referenced by: '<S142>/Coefficient of Friction vs Velocity'
   */
  { -0.4, -0.4, -0.8, 0.8, 0.4, 0.4 },

  /* Expression: [-3 -1.5 -1 1 1.5 3]*vth
   * Referenced by: '<S142>/Coefficient of Friction vs Velocity'
   */
  { -0.00030000000000000003, -0.00015000000000000001, -0.0001, 0.0001,
    0.00015000000000000001, 0.00030000000000000003 },

  /* Expression: 1
   * Referenced by: '<S142>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S136>/Fx1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S136>/Gain'
   */
  -1.0,

  /* Expression: [0 0 -sphere_rad]
   * Referenced by: '<S136>/Fx2'
   */
  { 0.0, 0.0, -0.04 },

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S122>/Zeros'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: -inf
   * Referenced by: '<S178>/Dead Zone'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S178>/Dead Zone'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S178>/Gain2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S181>/Fx'
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S187>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S187>/Saturation'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S181>/Gain'
   */
  -1.0,

  /* Expression: [-muk -muk -mus mus  muk muk]
   * Referenced by: '<S186>/Coefficient of Friction vs Velocity'
   */
  { -0.4, -0.4, -0.8, 0.8, 0.4, 0.4 },

  /* Expression: [-3 -1.5 -1 1 1.5 3]*vth
   * Referenced by: '<S186>/Coefficient of Friction vs Velocity'
   */
  { -0.00030000000000000003, -0.00015000000000000001, -0.0001, 0.0001,
    0.00015000000000000001, 0.00030000000000000003 },

  /* Expression: 1
   * Referenced by: '<S186>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S180>/Fx1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S180>/Gain'
   */
  -1.0,

  /* Expression: [0 0 -sphere_rad]
   * Referenced by: '<S180>/Fx2'
   */
  { 0.0, 0.0, -0.04 },

  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S166>/Zeros'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: [0.3;0.2;0.6]
   * Referenced by: '<Root>/Constant'
   */
  { 0.3, 0.2, 0.6 },

  /* Expression: 1.9
   * Referenced by: '<Root>/Step1'
   */
  1.9,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step1'
   */
  1.0,

  /* Expression: 5*pi/180
   * Referenced by: '<Root>/Sine Wave'
   */
  0.087266462599716474,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: -2
   * Referenced by: '<Root>/Sine Wave'
   */
  -2.0,

  /* Expression: 2
   * Referenced by: '<Root>/Step'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S30>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S30>/Gain1'
   */
  2.0,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S12>/Merge'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S74>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S74>/Gain1'
   */
  2.0,

  /* Computed Parameter: Merge_InitialOutput_o
   * Referenced by: '<S13>/Merge'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S118>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S118>/Gain1'
   */
  2.0,

  /* Computed Parameter: Merge_InitialOutput_d
   * Referenced by: '<S14>/Merge'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S162>/Gain'
   */
  2.0,

  /* Expression: 2
   * Referenced by: '<S162>/Gain1'
   */
  2.0,

  /* Computed Parameter: Merge_InitialOutput_h
   * Referenced by: '<S15>/Merge'
   */
  0.0
};
