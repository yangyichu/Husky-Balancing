/*
 * robot_simple_balancing.c
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

/* Block signals (default storage) */
B_robot_simple_balancing_T robot_simple_balancing_B;

/* Continuous states */
X_robot_simple_balancing_T robot_simple_balancing_X;

/* Block states (default storage) */
DW_robot_simple_balancing_T robot_simple_balancing_DW;

/* Real-time model */
RT_MODEL_robot_simple_balanci_T robot_simple_balancing_M_;
RT_MODEL_robot_simple_balanci_T *const robot_simple_balancing_M =
  &robot_simple_balancing_M_;

/* Forward declaration for local functions */
static void robot_simple_balancing_inv(const real_T x[9], real_T y[9]);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Projection for root system: '<Root>' */
void robot_simple_balancing_projection(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[272];
  int_T tmp_1[69];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;

  /* Projection for SimscapeExecutionBlock: '<S29>/STATE_1' */
  simulationData = (NeslSimulationData *)
    robot_simple_balancing_DW.STATE_1_SimData;
  time = robot_simple_balancing_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX =
    &robot_simple_balancing_X.robot_simple_balancingx6_DOF_Jo[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &robot_simple_balancing_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX =
    &robot_simple_balancing_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (robot_simple_balancing_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&robot_simple_balancing_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = robot_simple_balancing_B.INPUT_1_1_1[0];
  tmp_0[1] = robot_simple_balancing_B.INPUT_1_1_1[1];
  tmp_0[2] = robot_simple_balancing_B.INPUT_1_1_1[2];
  tmp_0[3] = robot_simple_balancing_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = robot_simple_balancing_B.INPUT_2_1_1[0];
  tmp_0[5] = robot_simple_balancing_B.INPUT_2_1_1[1];
  tmp_0[6] = robot_simple_balancing_B.INPUT_2_1_1[2];
  tmp_0[7] = robot_simple_balancing_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = robot_simple_balancing_B.INPUT_3_1_1[0];
  tmp_0[9] = robot_simple_balancing_B.INPUT_3_1_1[1];
  tmp_0[10] = robot_simple_balancing_B.INPUT_3_1_1[2];
  tmp_0[11] = robot_simple_balancing_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = robot_simple_balancing_B.INPUT_4_1_1[0];
  tmp_0[13] = robot_simple_balancing_B.INPUT_4_1_1[1];
  tmp_0[14] = robot_simple_balancing_B.INPUT_4_1_1[2];
  tmp_0[15] = robot_simple_balancing_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = robot_simple_balancing_B.INPUT_23_1_1[0];
  tmp_0[17] = robot_simple_balancing_B.INPUT_23_1_1[1];
  tmp_0[18] = robot_simple_balancing_B.INPUT_23_1_1[2];
  tmp_0[19] = robot_simple_balancing_B.INPUT_23_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = robot_simple_balancing_B.INPUT_21_1_1[0];
  tmp_0[21] = robot_simple_balancing_B.INPUT_21_1_1[1];
  tmp_0[22] = robot_simple_balancing_B.INPUT_21_1_1[2];
  tmp_0[23] = robot_simple_balancing_B.INPUT_21_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = robot_simple_balancing_B.INPUT_22_1_1[0];
  tmp_0[25] = robot_simple_balancing_B.INPUT_22_1_1[1];
  tmp_0[26] = robot_simple_balancing_B.INPUT_22_1_1[2];
  tmp_0[27] = robot_simple_balancing_B.INPUT_22_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = robot_simple_balancing_B.INPUT_24_1_1[0];
  tmp_0[29] = robot_simple_balancing_B.INPUT_24_1_1[1];
  tmp_0[30] = robot_simple_balancing_B.INPUT_24_1_1[2];
  tmp_0[31] = robot_simple_balancing_B.INPUT_24_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = robot_simple_balancing_B.INPUT_27_1_1[0];
  tmp_0[33] = robot_simple_balancing_B.INPUT_27_1_1[1];
  tmp_0[34] = robot_simple_balancing_B.INPUT_27_1_1[2];
  tmp_0[35] = robot_simple_balancing_B.INPUT_27_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = robot_simple_balancing_B.INPUT_25_1_1[0];
  tmp_0[37] = robot_simple_balancing_B.INPUT_25_1_1[1];
  tmp_0[38] = robot_simple_balancing_B.INPUT_25_1_1[2];
  tmp_0[39] = robot_simple_balancing_B.INPUT_25_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = robot_simple_balancing_B.INPUT_26_1_1[0];
  tmp_0[41] = robot_simple_balancing_B.INPUT_26_1_1[1];
  tmp_0[42] = robot_simple_balancing_B.INPUT_26_1_1[2];
  tmp_0[43] = robot_simple_balancing_B.INPUT_26_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = robot_simple_balancing_B.INPUT_28_1_1[0];
  tmp_0[45] = robot_simple_balancing_B.INPUT_28_1_1[1];
  tmp_0[46] = robot_simple_balancing_B.INPUT_28_1_1[2];
  tmp_0[47] = robot_simple_balancing_B.INPUT_28_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = robot_simple_balancing_B.INPUT_31_1_1[0];
  tmp_0[49] = robot_simple_balancing_B.INPUT_31_1_1[1];
  tmp_0[50] = robot_simple_balancing_B.INPUT_31_1_1[2];
  tmp_0[51] = robot_simple_balancing_B.INPUT_31_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = robot_simple_balancing_B.INPUT_29_1_1[0];
  tmp_0[53] = robot_simple_balancing_B.INPUT_29_1_1[1];
  tmp_0[54] = robot_simple_balancing_B.INPUT_29_1_1[2];
  tmp_0[55] = robot_simple_balancing_B.INPUT_29_1_1[3];
  tmp_1[14] = 56;
  tmp_0[56] = robot_simple_balancing_B.INPUT_30_1_1[0];
  tmp_0[57] = robot_simple_balancing_B.INPUT_30_1_1[1];
  tmp_0[58] = robot_simple_balancing_B.INPUT_30_1_1[2];
  tmp_0[59] = robot_simple_balancing_B.INPUT_30_1_1[3];
  tmp_1[15] = 60;
  tmp_0[60] = robot_simple_balancing_B.INPUT_32_1_1[0];
  tmp_0[61] = robot_simple_balancing_B.INPUT_32_1_1[1];
  tmp_0[62] = robot_simple_balancing_B.INPUT_32_1_1[2];
  tmp_0[63] = robot_simple_balancing_B.INPUT_32_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = robot_simple_balancing_B.INPUT_35_1_1[0];
  tmp_0[65] = robot_simple_balancing_B.INPUT_35_1_1[1];
  tmp_0[66] = robot_simple_balancing_B.INPUT_35_1_1[2];
  tmp_0[67] = robot_simple_balancing_B.INPUT_35_1_1[3];
  tmp_1[17] = 68;
  tmp_0[68] = robot_simple_balancing_B.INPUT_33_1_1[0];
  tmp_0[69] = robot_simple_balancing_B.INPUT_33_1_1[1];
  tmp_0[70] = robot_simple_balancing_B.INPUT_33_1_1[2];
  tmp_0[71] = robot_simple_balancing_B.INPUT_33_1_1[3];
  tmp_1[18] = 72;
  tmp_0[72] = robot_simple_balancing_B.INPUT_34_1_1[0];
  tmp_0[73] = robot_simple_balancing_B.INPUT_34_1_1[1];
  tmp_0[74] = robot_simple_balancing_B.INPUT_34_1_1[2];
  tmp_0[75] = robot_simple_balancing_B.INPUT_34_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = robot_simple_balancing_B.INPUT_36_1_1[0];
  tmp_0[77] = robot_simple_balancing_B.INPUT_36_1_1[1];
  tmp_0[78] = robot_simple_balancing_B.INPUT_36_1_1[2];
  tmp_0[79] = robot_simple_balancing_B.INPUT_36_1_1[3];
  tmp_1[20] = 80;
  tmp_0[80] = robot_simple_balancing_B.INPUT_8_1_1[0];
  tmp_0[81] = robot_simple_balancing_B.INPUT_8_1_1[1];
  tmp_0[82] = robot_simple_balancing_B.INPUT_8_1_1[2];
  tmp_0[83] = robot_simple_balancing_B.INPUT_8_1_1[3];
  tmp_1[21] = 84;
  tmp_0[84] = robot_simple_balancing_B.INPUT_8_1_2[0];
  tmp_0[85] = robot_simple_balancing_B.INPUT_8_1_2[1];
  tmp_0[86] = robot_simple_balancing_B.INPUT_8_1_2[2];
  tmp_0[87] = robot_simple_balancing_B.INPUT_8_1_2[3];
  tmp_1[22] = 88;
  tmp_0[88] = robot_simple_balancing_B.INPUT_8_1_3[0];
  tmp_0[89] = robot_simple_balancing_B.INPUT_8_1_3[1];
  tmp_0[90] = robot_simple_balancing_B.INPUT_8_1_3[2];
  tmp_0[91] = robot_simple_balancing_B.INPUT_8_1_3[3];
  tmp_1[23] = 92;
  tmp_0[92] = robot_simple_balancing_B.INPUT_7_1_1[0];
  tmp_0[93] = robot_simple_balancing_B.INPUT_7_1_1[1];
  tmp_0[94] = robot_simple_balancing_B.INPUT_7_1_1[2];
  tmp_0[95] = robot_simple_balancing_B.INPUT_7_1_1[3];
  tmp_1[24] = 96;
  tmp_0[96] = robot_simple_balancing_B.INPUT_7_1_2[0];
  tmp_0[97] = robot_simple_balancing_B.INPUT_7_1_2[1];
  tmp_0[98] = robot_simple_balancing_B.INPUT_7_1_2[2];
  tmp_0[99] = robot_simple_balancing_B.INPUT_7_1_2[3];
  tmp_1[25] = 100;
  tmp_0[100] = robot_simple_balancing_B.INPUT_7_1_3[0];
  tmp_0[101] = robot_simple_balancing_B.INPUT_7_1_3[1];
  tmp_0[102] = robot_simple_balancing_B.INPUT_7_1_3[2];
  tmp_0[103] = robot_simple_balancing_B.INPUT_7_1_3[3];
  tmp_1[26] = 104;
  tmp_0[104] = robot_simple_balancing_B.INPUT_5_1_1[0];
  tmp_0[105] = robot_simple_balancing_B.INPUT_5_1_1[1];
  tmp_0[106] = robot_simple_balancing_B.INPUT_5_1_1[2];
  tmp_0[107] = robot_simple_balancing_B.INPUT_5_1_1[3];
  tmp_1[27] = 108;
  tmp_0[108] = robot_simple_balancing_B.INPUT_5_1_2[0];
  tmp_0[109] = robot_simple_balancing_B.INPUT_5_1_2[1];
  tmp_0[110] = robot_simple_balancing_B.INPUT_5_1_2[2];
  tmp_0[111] = robot_simple_balancing_B.INPUT_5_1_2[3];
  tmp_1[28] = 112;
  tmp_0[112] = robot_simple_balancing_B.INPUT_5_1_3[0];
  tmp_0[113] = robot_simple_balancing_B.INPUT_5_1_3[1];
  tmp_0[114] = robot_simple_balancing_B.INPUT_5_1_3[2];
  tmp_0[115] = robot_simple_balancing_B.INPUT_5_1_3[3];
  tmp_1[29] = 116;
  tmp_0[116] = robot_simple_balancing_B.INPUT_6_1_1[0];
  tmp_0[117] = robot_simple_balancing_B.INPUT_6_1_1[1];
  tmp_0[118] = robot_simple_balancing_B.INPUT_6_1_1[2];
  tmp_0[119] = robot_simple_balancing_B.INPUT_6_1_1[3];
  tmp_1[30] = 120;
  tmp_0[120] = robot_simple_balancing_B.INPUT_6_1_2[0];
  tmp_0[121] = robot_simple_balancing_B.INPUT_6_1_2[1];
  tmp_0[122] = robot_simple_balancing_B.INPUT_6_1_2[2];
  tmp_0[123] = robot_simple_balancing_B.INPUT_6_1_2[3];
  tmp_1[31] = 124;
  tmp_0[124] = robot_simple_balancing_B.INPUT_6_1_3[0];
  tmp_0[125] = robot_simple_balancing_B.INPUT_6_1_3[1];
  tmp_0[126] = robot_simple_balancing_B.INPUT_6_1_3[2];
  tmp_0[127] = robot_simple_balancing_B.INPUT_6_1_3[3];
  tmp_1[32] = 128;
  tmp_0[128] = robot_simple_balancing_B.INPUT_12_1_1[0];
  tmp_0[129] = robot_simple_balancing_B.INPUT_12_1_1[1];
  tmp_0[130] = robot_simple_balancing_B.INPUT_12_1_1[2];
  tmp_0[131] = robot_simple_balancing_B.INPUT_12_1_1[3];
  tmp_1[33] = 132;
  tmp_0[132] = robot_simple_balancing_B.INPUT_12_1_2[0];
  tmp_0[133] = robot_simple_balancing_B.INPUT_12_1_2[1];
  tmp_0[134] = robot_simple_balancing_B.INPUT_12_1_2[2];
  tmp_0[135] = robot_simple_balancing_B.INPUT_12_1_2[3];
  tmp_1[34] = 136;
  tmp_0[136] = robot_simple_balancing_B.INPUT_12_1_3[0];
  tmp_0[137] = robot_simple_balancing_B.INPUT_12_1_3[1];
  tmp_0[138] = robot_simple_balancing_B.INPUT_12_1_3[2];
  tmp_0[139] = robot_simple_balancing_B.INPUT_12_1_3[3];
  tmp_1[35] = 140;
  tmp_0[140] = robot_simple_balancing_B.INPUT_11_1_1[0];
  tmp_0[141] = robot_simple_balancing_B.INPUT_11_1_1[1];
  tmp_0[142] = robot_simple_balancing_B.INPUT_11_1_1[2];
  tmp_0[143] = robot_simple_balancing_B.INPUT_11_1_1[3];
  tmp_1[36] = 144;
  tmp_0[144] = robot_simple_balancing_B.INPUT_11_1_2[0];
  tmp_0[145] = robot_simple_balancing_B.INPUT_11_1_2[1];
  tmp_0[146] = robot_simple_balancing_B.INPUT_11_1_2[2];
  tmp_0[147] = robot_simple_balancing_B.INPUT_11_1_2[3];
  tmp_1[37] = 148;
  tmp_0[148] = robot_simple_balancing_B.INPUT_11_1_3[0];
  tmp_0[149] = robot_simple_balancing_B.INPUT_11_1_3[1];
  tmp_0[150] = robot_simple_balancing_B.INPUT_11_1_3[2];
  tmp_0[151] = robot_simple_balancing_B.INPUT_11_1_3[3];
  tmp_1[38] = 152;
  tmp_0[152] = robot_simple_balancing_B.INPUT_9_1_1[0];
  tmp_0[153] = robot_simple_balancing_B.INPUT_9_1_1[1];
  tmp_0[154] = robot_simple_balancing_B.INPUT_9_1_1[2];
  tmp_0[155] = robot_simple_balancing_B.INPUT_9_1_1[3];
  tmp_1[39] = 156;
  tmp_0[156] = robot_simple_balancing_B.INPUT_9_1_2[0];
  tmp_0[157] = robot_simple_balancing_B.INPUT_9_1_2[1];
  tmp_0[158] = robot_simple_balancing_B.INPUT_9_1_2[2];
  tmp_0[159] = robot_simple_balancing_B.INPUT_9_1_2[3];
  tmp_1[40] = 160;
  tmp_0[160] = robot_simple_balancing_B.INPUT_9_1_3[0];
  tmp_0[161] = robot_simple_balancing_B.INPUT_9_1_3[1];
  tmp_0[162] = robot_simple_balancing_B.INPUT_9_1_3[2];
  tmp_0[163] = robot_simple_balancing_B.INPUT_9_1_3[3];
  tmp_1[41] = 164;
  tmp_0[164] = robot_simple_balancing_B.INPUT_10_1_1[0];
  tmp_0[165] = robot_simple_balancing_B.INPUT_10_1_1[1];
  tmp_0[166] = robot_simple_balancing_B.INPUT_10_1_1[2];
  tmp_0[167] = robot_simple_balancing_B.INPUT_10_1_1[3];
  tmp_1[42] = 168;
  tmp_0[168] = robot_simple_balancing_B.INPUT_10_1_2[0];
  tmp_0[169] = robot_simple_balancing_B.INPUT_10_1_2[1];
  tmp_0[170] = robot_simple_balancing_B.INPUT_10_1_2[2];
  tmp_0[171] = robot_simple_balancing_B.INPUT_10_1_2[3];
  tmp_1[43] = 172;
  tmp_0[172] = robot_simple_balancing_B.INPUT_10_1_3[0];
  tmp_0[173] = robot_simple_balancing_B.INPUT_10_1_3[1];
  tmp_0[174] = robot_simple_balancing_B.INPUT_10_1_3[2];
  tmp_0[175] = robot_simple_balancing_B.INPUT_10_1_3[3];
  tmp_1[44] = 176;
  tmp_0[176] = robot_simple_balancing_B.INPUT_16_1_1[0];
  tmp_0[177] = robot_simple_balancing_B.INPUT_16_1_1[1];
  tmp_0[178] = robot_simple_balancing_B.INPUT_16_1_1[2];
  tmp_0[179] = robot_simple_balancing_B.INPUT_16_1_1[3];
  tmp_1[45] = 180;
  tmp_0[180] = robot_simple_balancing_B.INPUT_16_1_2[0];
  tmp_0[181] = robot_simple_balancing_B.INPUT_16_1_2[1];
  tmp_0[182] = robot_simple_balancing_B.INPUT_16_1_2[2];
  tmp_0[183] = robot_simple_balancing_B.INPUT_16_1_2[3];
  tmp_1[46] = 184;
  tmp_0[184] = robot_simple_balancing_B.INPUT_16_1_3[0];
  tmp_0[185] = robot_simple_balancing_B.INPUT_16_1_3[1];
  tmp_0[186] = robot_simple_balancing_B.INPUT_16_1_3[2];
  tmp_0[187] = robot_simple_balancing_B.INPUT_16_1_3[3];
  tmp_1[47] = 188;
  tmp_0[188] = robot_simple_balancing_B.INPUT_15_1_1[0];
  tmp_0[189] = robot_simple_balancing_B.INPUT_15_1_1[1];
  tmp_0[190] = robot_simple_balancing_B.INPUT_15_1_1[2];
  tmp_0[191] = robot_simple_balancing_B.INPUT_15_1_1[3];
  tmp_1[48] = 192;
  tmp_0[192] = robot_simple_balancing_B.INPUT_15_1_2[0];
  tmp_0[193] = robot_simple_balancing_B.INPUT_15_1_2[1];
  tmp_0[194] = robot_simple_balancing_B.INPUT_15_1_2[2];
  tmp_0[195] = robot_simple_balancing_B.INPUT_15_1_2[3];
  tmp_1[49] = 196;
  tmp_0[196] = robot_simple_balancing_B.INPUT_15_1_3[0];
  tmp_0[197] = robot_simple_balancing_B.INPUT_15_1_3[1];
  tmp_0[198] = robot_simple_balancing_B.INPUT_15_1_3[2];
  tmp_0[199] = robot_simple_balancing_B.INPUT_15_1_3[3];
  tmp_1[50] = 200;
  tmp_0[200] = robot_simple_balancing_B.INPUT_13_1_1[0];
  tmp_0[201] = robot_simple_balancing_B.INPUT_13_1_1[1];
  tmp_0[202] = robot_simple_balancing_B.INPUT_13_1_1[2];
  tmp_0[203] = robot_simple_balancing_B.INPUT_13_1_1[3];
  tmp_1[51] = 204;
  tmp_0[204] = robot_simple_balancing_B.INPUT_13_1_2[0];
  tmp_0[205] = robot_simple_balancing_B.INPUT_13_1_2[1];
  tmp_0[206] = robot_simple_balancing_B.INPUT_13_1_2[2];
  tmp_0[207] = robot_simple_balancing_B.INPUT_13_1_2[3];
  tmp_1[52] = 208;
  tmp_0[208] = robot_simple_balancing_B.INPUT_13_1_3[0];
  tmp_0[209] = robot_simple_balancing_B.INPUT_13_1_3[1];
  tmp_0[210] = robot_simple_balancing_B.INPUT_13_1_3[2];
  tmp_0[211] = robot_simple_balancing_B.INPUT_13_1_3[3];
  tmp_1[53] = 212;
  tmp_0[212] = robot_simple_balancing_B.INPUT_14_1_1[0];
  tmp_0[213] = robot_simple_balancing_B.INPUT_14_1_1[1];
  tmp_0[214] = robot_simple_balancing_B.INPUT_14_1_1[2];
  tmp_0[215] = robot_simple_balancing_B.INPUT_14_1_1[3];
  tmp_1[54] = 216;
  tmp_0[216] = robot_simple_balancing_B.INPUT_14_1_2[0];
  tmp_0[217] = robot_simple_balancing_B.INPUT_14_1_2[1];
  tmp_0[218] = robot_simple_balancing_B.INPUT_14_1_2[2];
  tmp_0[219] = robot_simple_balancing_B.INPUT_14_1_2[3];
  tmp_1[55] = 220;
  tmp_0[220] = robot_simple_balancing_B.INPUT_14_1_3[0];
  tmp_0[221] = robot_simple_balancing_B.INPUT_14_1_3[1];
  tmp_0[222] = robot_simple_balancing_B.INPUT_14_1_3[2];
  tmp_0[223] = robot_simple_balancing_B.INPUT_14_1_3[3];
  tmp_1[56] = 224;
  tmp_0[224] = robot_simple_balancing_B.INPUT_20_1_1[0];
  tmp_0[225] = robot_simple_balancing_B.INPUT_20_1_1[1];
  tmp_0[226] = robot_simple_balancing_B.INPUT_20_1_1[2];
  tmp_0[227] = robot_simple_balancing_B.INPUT_20_1_1[3];
  tmp_1[57] = 228;
  tmp_0[228] = robot_simple_balancing_B.INPUT_20_1_2[0];
  tmp_0[229] = robot_simple_balancing_B.INPUT_20_1_2[1];
  tmp_0[230] = robot_simple_balancing_B.INPUT_20_1_2[2];
  tmp_0[231] = robot_simple_balancing_B.INPUT_20_1_2[3];
  tmp_1[58] = 232;
  tmp_0[232] = robot_simple_balancing_B.INPUT_20_1_3[0];
  tmp_0[233] = robot_simple_balancing_B.INPUT_20_1_3[1];
  tmp_0[234] = robot_simple_balancing_B.INPUT_20_1_3[2];
  tmp_0[235] = robot_simple_balancing_B.INPUT_20_1_3[3];
  tmp_1[59] = 236;
  tmp_0[236] = robot_simple_balancing_B.INPUT_19_1_1[0];
  tmp_0[237] = robot_simple_balancing_B.INPUT_19_1_1[1];
  tmp_0[238] = robot_simple_balancing_B.INPUT_19_1_1[2];
  tmp_0[239] = robot_simple_balancing_B.INPUT_19_1_1[3];
  tmp_1[60] = 240;
  tmp_0[240] = robot_simple_balancing_B.INPUT_19_1_2[0];
  tmp_0[241] = robot_simple_balancing_B.INPUT_19_1_2[1];
  tmp_0[242] = robot_simple_balancing_B.INPUT_19_1_2[2];
  tmp_0[243] = robot_simple_balancing_B.INPUT_19_1_2[3];
  tmp_1[61] = 244;
  tmp_0[244] = robot_simple_balancing_B.INPUT_19_1_3[0];
  tmp_0[245] = robot_simple_balancing_B.INPUT_19_1_3[1];
  tmp_0[246] = robot_simple_balancing_B.INPUT_19_1_3[2];
  tmp_0[247] = robot_simple_balancing_B.INPUT_19_1_3[3];
  tmp_1[62] = 248;
  tmp_0[248] = robot_simple_balancing_B.INPUT_17_1_1[0];
  tmp_0[249] = robot_simple_balancing_B.INPUT_17_1_1[1];
  tmp_0[250] = robot_simple_balancing_B.INPUT_17_1_1[2];
  tmp_0[251] = robot_simple_balancing_B.INPUT_17_1_1[3];
  tmp_1[63] = 252;
  tmp_0[252] = robot_simple_balancing_B.INPUT_17_1_2[0];
  tmp_0[253] = robot_simple_balancing_B.INPUT_17_1_2[1];
  tmp_0[254] = robot_simple_balancing_B.INPUT_17_1_2[2];
  tmp_0[255] = robot_simple_balancing_B.INPUT_17_1_2[3];
  tmp_1[64] = 256;
  tmp_0[256] = robot_simple_balancing_B.INPUT_17_1_3[0];
  tmp_0[257] = robot_simple_balancing_B.INPUT_17_1_3[1];
  tmp_0[258] = robot_simple_balancing_B.INPUT_17_1_3[2];
  tmp_0[259] = robot_simple_balancing_B.INPUT_17_1_3[3];
  tmp_1[65] = 260;
  tmp_0[260] = robot_simple_balancing_B.INPUT_18_1_1[0];
  tmp_0[261] = robot_simple_balancing_B.INPUT_18_1_1[1];
  tmp_0[262] = robot_simple_balancing_B.INPUT_18_1_1[2];
  tmp_0[263] = robot_simple_balancing_B.INPUT_18_1_1[3];
  tmp_1[66] = 264;
  tmp_0[264] = robot_simple_balancing_B.INPUT_18_1_2[0];
  tmp_0[265] = robot_simple_balancing_B.INPUT_18_1_2[1];
  tmp_0[266] = robot_simple_balancing_B.INPUT_18_1_2[2];
  tmp_0[267] = robot_simple_balancing_B.INPUT_18_1_2[3];
  tmp_1[67] = 268;
  tmp_0[268] = robot_simple_balancing_B.INPUT_18_1_3[0];
  tmp_0[269] = robot_simple_balancing_B.INPUT_18_1_3[1];
  tmp_0[270] = robot_simple_balancing_B.INPUT_18_1_3[2];
  tmp_0[271] = robot_simple_balancing_B.INPUT_18_1_3[3];
  tmp_1[68] = 272;
  simulationData->mData->mInputValues.mN = 272;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 69;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  diagnosticManager = (NeuDiagnosticManager *)
    robot_simple_balancing_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    robot_simple_balancing_DW.STATE_1_Simulator, NESL_SIM_PROJECTION,
    simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(robot_simple_balancing_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S29>/STATE_1' */
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 53;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  robot_simple_balancing_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  robot_simple_balancing_step();
  robot_simple_balancing_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  robot_simple_balancing_step();
  robot_simple_balancing_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  robot_simple_balancing_step();
  robot_simple_balancing_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  robot_simple_balancing_step();
  robot_simple_balancing_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void robot_simple_balancing_inv(const real_T x[9], real_T y[9])
{
  real_T b_x[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T itmp;
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = fabs(x[0]);
  absx21 = fabs(x[1]);
  absx31 = fabs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
  } else {
    if (absx31 > absx11) {
      p1 = 6;
      p3 = 0;
      b_x[0] = x[2];
      b_x[2] = x[0];
      b_x[3] = x[5];
      b_x[5] = x[3];
      b_x[6] = x[8];
      b_x[8] = x[6];
    }
  }

  absx31 = b_x[1] / b_x[0];
  b_x[1] = absx31;
  absx11 = b_x[2] / b_x[0];
  b_x[2] = absx11;
  b_x[4] -= absx31 * b_x[3];
  b_x[5] -= absx11 * b_x[3];
  b_x[7] -= absx31 * b_x[6];
  b_x[8] -= absx11 * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    b_x[1] = absx11;
    b_x[2] = absx31;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
  }

  absx31 = b_x[5] / b_x[4];
  b_x[8] -= absx31 * b_x[7];
  absx11 = (absx31 * b_x[1] - b_x[2]) / b_x[8];
  absx21 = -(b_x[7] * absx11 + b_x[1]) / b_x[4];
  y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -absx31 / b_x[8];
  absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
  y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / b_x[8];
  absx21 = -b_x[7] * absx11 / b_x[4];
  y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void rt_mldivide_U1d3x3_U2d_9O8lG8ax(const real_T u0[9], const real_T u1[3],
  real_T y[3])
{
  real_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&A[0], &u0[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u0[0]);
  a21 = fabs(u0[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u0[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u0[r2] / u0[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[1] = u1[r2] - u1[r1] * A[r2];
  y[2] = (u1[r3] - u1[r1] * A[r3]) - A[r3 + 3] * y[1];
  y[2] /= A[r3 + 6];
  y[0] = u1[r1] - A[r1 + 6] * y[2];
  y[1] -= A[r2 + 6] * y[2];
  y[1] /= A[r2 + 3];
  y[0] -= A[r1 + 3] * y[1];
  y[0] /= A[r1];
}

/* Model step function */
void robot_simple_balancing_step(void)
{
  if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
    /* set solver stop time */
    if (!(robot_simple_balancing_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&robot_simple_balancing_M->solverInfo,
                            ((robot_simple_balancing_M->Timing.clockTickH0 + 1) *
        robot_simple_balancing_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&robot_simple_balancing_M->solverInfo,
                            ((robot_simple_balancing_M->Timing.clockTick0 + 1) *
        robot_simple_balancing_M->Timing.stepSize0 +
        robot_simple_balancing_M->Timing.clockTickH0 *
        robot_simple_balancing_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(robot_simple_balancing_M)) {
    robot_simple_balancing_M->Timing.t[0] = rtsiGetT
      (&robot_simple_balancing_M->solverInfo);
  }

  {
    boolean_T first_output;
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[272];
    int_T tmp_1[69];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T time_0;
    real_T tmp_2[285];
    int_T tmp_3[70];
    real_T p_new[3];
    real_T p_t_new[12];
    real_T rtb_DataTypeConversion;
    real_T rtb_Abs1;
    int8_T rtAction;
    real_T rtb_Signx_e;
    real_T rtb_SprForce_d;
    real_T rtb_Product_as;
    real_T rtb_Product1_cj[3];
    real_T rtb_Product1_o;
    real_T rtb_Product3_j;
    real_T rtb_Product1_bz;
    real_T rtb_Product_m;
    real_T rtb_TmpSignalConversionAtProd_d[3];
    real_T p_new_tmp[9];
    int32_T i;
    real_T rtb_Signx_p[3];
    real_T rtb_Signx_p_0[3];
    real_T rtb_Signx_p_1[3];
    real_T rtb_Signx_p_2[3];
    int32_T i_0;
    int32_T p_t_new_tmp;
    static const real_T d[12] = { 0.3, 0.2, 0.6, 0.3, -0.2, 0.6, -0.3, 0.2, 0.6,
      -0.3, -0.2, 0.6 };

    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      /* Delay: '<Root>/Delay' */
      memcpy(&robot_simple_balancing_B.Delay[0],
             &robot_simple_balancing_DW.Delay_DSTATE[0], 9U * sizeof(real_T));
    }

    /* Step: '<Root>/Step1' incorporates:
     *  Sin: '<Root>/Sine Wave'
     *  Step: '<Root>/Step'
     */
    rtb_DataTypeConversion = robot_simple_balancing_M->Timing.t[0];
    if (rtb_DataTypeConversion < robot_simple_balancing_P.Step1_Time) {
      rtb_Abs1 = robot_simple_balancing_P.Step1_Y0;
    } else {
      rtb_Abs1 = robot_simple_balancing_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (!(rtb_Abs1 == 0.0)) {
      robot_simple_balancing_inv(robot_simple_balancing_B.Delay, p_new_tmp);
      for (i = 0; i < 3; i++) {
        rtb_Abs1 = p_new_tmp[i + 3];
        rtb_Signx_e = p_new_tmp[i + 6];
        for (i_0 = 0; i_0 < 4; i_0++) {
          p_t_new_tmp = i + 3 * i_0;
          p_t_new[p_t_new_tmp] = 0.0;
          p_t_new[p_t_new_tmp] += d[3 * i_0] * p_new_tmp[i];
          p_t_new[p_t_new_tmp] += d[3 * i_0 + 1] * rtb_Abs1;
          p_t_new[p_t_new_tmp] += d[3 * i_0 + 2] * rtb_Signx_e;
        }

        p_new[i] = rtb_Signx_e * robot_simple_balancing_P.Constant_Value[2] +
          (rtb_Abs1 * robot_simple_balancing_P.Constant_Value[1] + p_new_tmp[i] *
           robot_simple_balancing_P.Constant_Value[0]);
      }

      robot_simple_balancing_B.x = p_new[0];
      robot_simple_balancing_B.y = p_new[1];
      robot_simple_balancing_B.z = p_new[2];
      memset(&robot_simple_balancing_B.d_leg[0], 0, sizeof(real_T) << 4U);
      rtb_Abs1 = 0.3 - p_t_new[0];
      robot_simple_balancing_B.d_leg[3] = rtb_Abs1 * rtb_Abs1;
      rtb_Abs1 = 0.2 - p_t_new[1];
      robot_simple_balancing_B.d_leg[7] = rtb_Abs1 * rtb_Abs1;
      rtb_Abs1 = 0.0 - p_t_new[2];
      robot_simple_balancing_B.d_leg[11] = rtb_Abs1 * rtb_Abs1 - 0.36;
      rtb_Abs1 = 0.3 - p_t_new[3];
      robot_simple_balancing_B.d_leg[15] = rtb_Abs1 * rtb_Abs1;
    } else {
      robot_simple_balancing_B.x = robot_simple_balancing_P.Constant_Value[0];
      robot_simple_balancing_B.y = robot_simple_balancing_P.Constant_Value[1];
      robot_simple_balancing_B.z = robot_simple_balancing_P.Constant_Value[2];
      memset(&robot_simple_balancing_B.d_leg[0], 0, sizeof(real_T) << 4U);
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* SimscapeInputBlock: '<S29>/INPUT_1_1_1' */
    if (robot_simple_balancing_DW.INPUT_1_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_1_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSPConv6ou[0] =
        robot_simple_balancing_B.x;
      robot_simple_balancing_X.robot_simple_balancingSPConv6ou[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_1_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSPConv6ou[0];
    robot_simple_balancing_B.INPUT_1_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSPConv6ou[1];
    robot_simple_balancing_B.INPUT_1_1_1[2] = ((robot_simple_balancing_B.x -
      robot_simple_balancing_X.robot_simple_balancingSPConv6ou[0]) * 1000.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSPConv6ou[1]) *
      1000.0;
    robot_simple_balancing_B.INPUT_1_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_1_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_2_1_1' */
    if (robot_simple_balancing_DW.INPUT_2_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_2_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSPConv7ou[0] =
        robot_simple_balancing_B.y;
      robot_simple_balancing_X.robot_simple_balancingSPConv7ou[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_2_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSPConv7ou[0];
    robot_simple_balancing_B.INPUT_2_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSPConv7ou[1];
    robot_simple_balancing_B.INPUT_2_1_1[2] = ((robot_simple_balancing_B.y -
      robot_simple_balancing_X.robot_simple_balancingSPConv7ou[0]) * 1000.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSPConv7ou[1]) *
      1000.0;
    robot_simple_balancing_B.INPUT_2_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_2_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_3_1_1' */
    if (robot_simple_balancing_DW.INPUT_3_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_3_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSPConv8ou[0] =
        robot_simple_balancing_B.z;
      robot_simple_balancing_X.robot_simple_balancingSPConv8ou[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_3_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSPConv8ou[0];
    robot_simple_balancing_B.INPUT_3_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSPConv8ou[1];
    robot_simple_balancing_B.INPUT_3_1_1[2] = ((robot_simple_balancing_B.z -
      robot_simple_balancing_X.robot_simple_balancingSPConv8ou[0]) * 1000.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSPConv8ou[1]) *
      1000.0;
    robot_simple_balancing_B.INPUT_3_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_3_1_1' */

    /* Step: '<Root>/Step' */
    if (rtb_DataTypeConversion < robot_simple_balancing_P.Step_Time) {
      rtb_Abs1 = robot_simple_balancing_P.Step_Y0;
    } else {
      rtb_Abs1 = robot_simple_balancing_P.Step_YFinal;
    }

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Sin: '<Root>/Sine Wave'
     */
    if (rtb_Abs1 > robot_simple_balancing_P.Switch_Threshold) {
      robot_simple_balancing_B.Switch = sin
        (robot_simple_balancing_P.SineWave_Freq * rtb_DataTypeConversion +
         robot_simple_balancing_P.SineWave_Phase) *
        robot_simple_balancing_P.SineWave_Amp +
        robot_simple_balancing_P.SineWave_Bias;
    } else {
      robot_simple_balancing_B.Switch = robot_simple_balancing_P.Constant1_Value;
    }

    /* End of Switch: '<Root>/Switch' */

    /* SimscapeInputBlock: '<S29>/INPUT_4_1_1' */
    if (robot_simple_balancing_DW.INPUT_4_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_4_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSimulink_[0] =
        robot_simple_balancing_B.Switch;
      robot_simple_balancing_X.robot_simple_balancingSimulink_[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_4_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSimulink_[0];
    robot_simple_balancing_B.INPUT_4_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSimulink_[1];
    robot_simple_balancing_B.INPUT_4_1_1[2] = ((robot_simple_balancing_B.Switch
      - robot_simple_balancing_X.robot_simple_balancingSimulink_[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSimulink_[1]) * 100.0;
    robot_simple_balancing_B.INPUT_4_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_4_1_1' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/desired_q '
     */
    for (i = 0; i < 16; i++) {
      robot_simple_balancing_B.Sum[i] = robot_simple_balancing_P.desired_q[i] +
        robot_simple_balancing_B.d_leg[i];
    }

    /* End of Sum: '<Root>/Sum' */

    /* SimscapeInputBlock: '<S29>/INPUT_23_1_1' */
    if (robot_simple_balancing_DW.INPUT_23_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_23_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsystem[0] =
        robot_simple_balancing_B.Sum[0];
      robot_simple_balancing_X.robot_simple_balancingSubsystem[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_23_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsystem[0];
    robot_simple_balancing_B.INPUT_23_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsystem[1];
    robot_simple_balancing_B.INPUT_23_1_1[2] = ((robot_simple_balancing_B.Sum[0]
      - robot_simple_balancing_X.robot_simple_balancingSubsystem[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsystem[1]) * 100.0;
    robot_simple_balancing_B.INPUT_23_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_23_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_21_1_1' */
    if (robot_simple_balancing_DW.INPUT_21_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_21_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_m[0] =
        robot_simple_balancing_B.Sum[1];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_m[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_21_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_m[0];
    robot_simple_balancing_B.INPUT_21_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_m[1];
    robot_simple_balancing_B.INPUT_21_1_1[2] = ((robot_simple_balancing_B.Sum[1]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_m[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_m[1]) * 100.0;
    robot_simple_balancing_B.INPUT_21_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_21_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_22_1_1' */
    if (robot_simple_balancing_DW.INPUT_22_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_22_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_o[0] =
        robot_simple_balancing_B.Sum[2];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_o[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_22_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_o[0];
    robot_simple_balancing_B.INPUT_22_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_o[1];
    robot_simple_balancing_B.INPUT_22_1_1[2] = ((robot_simple_balancing_B.Sum[2]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_o[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_o[1]) * 100.0;
    robot_simple_balancing_B.INPUT_22_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_22_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_24_1_1' */
    if (robot_simple_balancing_DW.INPUT_24_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_24_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_i[0] =
        robot_simple_balancing_B.Sum[3];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_i[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_24_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_i[0];
    robot_simple_balancing_B.INPUT_24_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_i[1];
    robot_simple_balancing_B.INPUT_24_1_1[2] = ((robot_simple_balancing_B.Sum[3]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_i[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_i[1]) * 100.0;
    robot_simple_balancing_B.INPUT_24_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_24_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_27_1_1' */
    if (robot_simple_balancing_DW.INPUT_27_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_27_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_d[0] =
        robot_simple_balancing_B.Sum[4];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_d[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_27_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_d[0];
    robot_simple_balancing_B.INPUT_27_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_d[1];
    robot_simple_balancing_B.INPUT_27_1_1[2] = ((robot_simple_balancing_B.Sum[4]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_d[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_d[1]) * 100.0;
    robot_simple_balancing_B.INPUT_27_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_27_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_25_1_1' */
    if (robot_simple_balancing_DW.INPUT_25_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_25_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsys_ie[0] =
        robot_simple_balancing_B.Sum[5];
      robot_simple_balancing_X.robot_simple_balancingSubsys_ie[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_25_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_ie[0];
    robot_simple_balancing_B.INPUT_25_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_ie[1];
    robot_simple_balancing_B.INPUT_25_1_1[2] = ((robot_simple_balancing_B.Sum[5]
      - robot_simple_balancing_X.robot_simple_balancingSubsys_ie[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_ie[1]) * 100.0;
    robot_simple_balancing_B.INPUT_25_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_25_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_26_1_1' */
    if (robot_simple_balancing_DW.INPUT_26_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_26_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_e[0] =
        robot_simple_balancing_B.Sum[6];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_e[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_26_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_e[0];
    robot_simple_balancing_B.INPUT_26_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_e[1];
    robot_simple_balancing_B.INPUT_26_1_1[2] = ((robot_simple_balancing_B.Sum[6]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_e[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_e[1]) * 100.0;
    robot_simple_balancing_B.INPUT_26_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_26_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_28_1_1' */
    if (robot_simple_balancing_DW.INPUT_28_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_28_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_f[0] =
        robot_simple_balancing_B.Sum[7];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_f[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_28_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_f[0];
    robot_simple_balancing_B.INPUT_28_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_f[1];
    robot_simple_balancing_B.INPUT_28_1_1[2] = ((robot_simple_balancing_B.Sum[7]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_f[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_f[1]) * 100.0;
    robot_simple_balancing_B.INPUT_28_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_28_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_31_1_1' */
    if (robot_simple_balancing_DW.INPUT_31_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_31_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_j[0] =
        robot_simple_balancing_B.Sum[8];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_j[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_31_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_j[0];
    robot_simple_balancing_B.INPUT_31_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_j[1];
    robot_simple_balancing_B.INPUT_31_1_1[2] = ((robot_simple_balancing_B.Sum[8]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_j[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_j[1]) * 100.0;
    robot_simple_balancing_B.INPUT_31_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_31_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_29_1_1' */
    if (robot_simple_balancing_DW.INPUT_29_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_29_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_k[0] =
        robot_simple_balancing_B.Sum[9];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_k[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_29_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_k[0];
    robot_simple_balancing_B.INPUT_29_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_k[1];
    robot_simple_balancing_B.INPUT_29_1_1[2] = ((robot_simple_balancing_B.Sum[9]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_k[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_k[1]) * 100.0;
    robot_simple_balancing_B.INPUT_29_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_29_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_30_1_1' */
    if (robot_simple_balancing_DW.INPUT_30_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_30_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsys_jm[0] =
        robot_simple_balancing_B.Sum[10];
      robot_simple_balancing_X.robot_simple_balancingSubsys_jm[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_30_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_jm[0];
    robot_simple_balancing_B.INPUT_30_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_jm[1];
    robot_simple_balancing_B.INPUT_30_1_1[2] = ((robot_simple_balancing_B.Sum[10]
      - robot_simple_balancing_X.robot_simple_balancingSubsys_jm[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_jm[1]) * 100.0;
    robot_simple_balancing_B.INPUT_30_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_30_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_32_1_1' */
    if (robot_simple_balancing_DW.INPUT_32_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_32_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_a[0] =
        robot_simple_balancing_B.Sum[11];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_a[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_32_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_a[0];
    robot_simple_balancing_B.INPUT_32_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_a[1];
    robot_simple_balancing_B.INPUT_32_1_1[2] = ((robot_simple_balancing_B.Sum[11]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_a[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_a[1]) * 100.0;
    robot_simple_balancing_B.INPUT_32_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_32_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_35_1_1' */
    if (robot_simple_balancing_DW.INPUT_35_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_35_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsys_ma[0] =
        robot_simple_balancing_B.Sum[12];
      robot_simple_balancing_X.robot_simple_balancingSubsys_ma[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_35_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_ma[0];
    robot_simple_balancing_B.INPUT_35_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_ma[1];
    robot_simple_balancing_B.INPUT_35_1_1[2] = ((robot_simple_balancing_B.Sum[12]
      - robot_simple_balancing_X.robot_simple_balancingSubsys_ma[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_ma[1]) * 100.0;
    robot_simple_balancing_B.INPUT_35_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_35_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_33_1_1' */
    if (robot_simple_balancing_DW.INPUT_33_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_33_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_l[0] =
        robot_simple_balancing_B.Sum[13];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_l[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_33_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_l[0];
    robot_simple_balancing_B.INPUT_33_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_l[1];
    robot_simple_balancing_B.INPUT_33_1_1[2] = ((robot_simple_balancing_B.Sum[13]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_l[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_l[1]) * 100.0;
    robot_simple_balancing_B.INPUT_33_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_33_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_34_1_1' */
    if (robot_simple_balancing_DW.INPUT_34_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_34_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsys_mm[0] =
        robot_simple_balancing_B.Sum[14];
      robot_simple_balancing_X.robot_simple_balancingSubsys_mm[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_34_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_mm[0];
    robot_simple_balancing_B.INPUT_34_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsys_mm[1];
    robot_simple_balancing_B.INPUT_34_1_1[2] = ((robot_simple_balancing_B.Sum[14]
      - robot_simple_balancing_X.robot_simple_balancingSubsys_mm[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_mm[1]) * 100.0;
    robot_simple_balancing_B.INPUT_34_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_34_1_1' */

    /* SimscapeInputBlock: '<S29>/INPUT_36_1_1' */
    if (robot_simple_balancing_DW.INPUT_36_1_1_FirstOutput == 0.0) {
      robot_simple_balancing_DW.INPUT_36_1_1_FirstOutput = 1.0;
      robot_simple_balancing_X.robot_simple_balancingSubsyst_p[0] =
        robot_simple_balancing_B.Sum[15];
      robot_simple_balancing_X.robot_simple_balancingSubsyst_p[1] = 0.0;
    }

    robot_simple_balancing_B.INPUT_36_1_1[0] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_p[0];
    robot_simple_balancing_B.INPUT_36_1_1[1] =
      robot_simple_balancing_X.robot_simple_balancingSubsyst_p[1];
    robot_simple_balancing_B.INPUT_36_1_1[2] = ((robot_simple_balancing_B.Sum[15]
      - robot_simple_balancing_X.robot_simple_balancingSubsyst_p[0]) * 100.0 -
      2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_p[1]) * 100.0;
    robot_simple_balancing_B.INPUT_36_1_1[3] = 0.0;

    /* End of SimscapeInputBlock: '<S29>/INPUT_36_1_1' */

    /* SimscapeExecutionBlock: '<S29>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S29>/OUTPUT_1_0'
     */
    simulationData = (NeslSimulationData *)
      robot_simple_balancing_DW.STATE_1_SimData;
    rtb_DataTypeConversion = robot_simple_balancing_M->Timing.t[0];
    time = rtb_DataTypeConversion;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX =
      &robot_simple_balancing_X.robot_simple_balancingx6_DOF_Jo[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &robot_simple_balancing_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &robot_simple_balancing_DW.STATE_1_Modes;
    first_output = false;
    simulationData->mData->mFoundZcEvents = first_output;
    first_output = rtmIsMajorTimeStep(robot_simple_balancing_M);
    simulationData->mData->mIsMajorTimeStep = first_output;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&robot_simple_balancing_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = robot_simple_balancing_B.INPUT_1_1_1[0];
    tmp_0[1] = robot_simple_balancing_B.INPUT_1_1_1[1];
    tmp_0[2] = robot_simple_balancing_B.INPUT_1_1_1[2];
    tmp_0[3] = robot_simple_balancing_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = robot_simple_balancing_B.INPUT_2_1_1[0];
    tmp_0[5] = robot_simple_balancing_B.INPUT_2_1_1[1];
    tmp_0[6] = robot_simple_balancing_B.INPUT_2_1_1[2];
    tmp_0[7] = robot_simple_balancing_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = robot_simple_balancing_B.INPUT_3_1_1[0];
    tmp_0[9] = robot_simple_balancing_B.INPUT_3_1_1[1];
    tmp_0[10] = robot_simple_balancing_B.INPUT_3_1_1[2];
    tmp_0[11] = robot_simple_balancing_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = robot_simple_balancing_B.INPUT_4_1_1[0];
    tmp_0[13] = robot_simple_balancing_B.INPUT_4_1_1[1];
    tmp_0[14] = robot_simple_balancing_B.INPUT_4_1_1[2];
    tmp_0[15] = robot_simple_balancing_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = robot_simple_balancing_B.INPUT_23_1_1[0];
    tmp_0[17] = robot_simple_balancing_B.INPUT_23_1_1[1];
    tmp_0[18] = robot_simple_balancing_B.INPUT_23_1_1[2];
    tmp_0[19] = robot_simple_balancing_B.INPUT_23_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = robot_simple_balancing_B.INPUT_21_1_1[0];
    tmp_0[21] = robot_simple_balancing_B.INPUT_21_1_1[1];
    tmp_0[22] = robot_simple_balancing_B.INPUT_21_1_1[2];
    tmp_0[23] = robot_simple_balancing_B.INPUT_21_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = robot_simple_balancing_B.INPUT_22_1_1[0];
    tmp_0[25] = robot_simple_balancing_B.INPUT_22_1_1[1];
    tmp_0[26] = robot_simple_balancing_B.INPUT_22_1_1[2];
    tmp_0[27] = robot_simple_balancing_B.INPUT_22_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = robot_simple_balancing_B.INPUT_24_1_1[0];
    tmp_0[29] = robot_simple_balancing_B.INPUT_24_1_1[1];
    tmp_0[30] = robot_simple_balancing_B.INPUT_24_1_1[2];
    tmp_0[31] = robot_simple_balancing_B.INPUT_24_1_1[3];
    tmp_1[8] = 32;
    tmp_0[32] = robot_simple_balancing_B.INPUT_27_1_1[0];
    tmp_0[33] = robot_simple_balancing_B.INPUT_27_1_1[1];
    tmp_0[34] = robot_simple_balancing_B.INPUT_27_1_1[2];
    tmp_0[35] = robot_simple_balancing_B.INPUT_27_1_1[3];
    tmp_1[9] = 36;
    tmp_0[36] = robot_simple_balancing_B.INPUT_25_1_1[0];
    tmp_0[37] = robot_simple_balancing_B.INPUT_25_1_1[1];
    tmp_0[38] = robot_simple_balancing_B.INPUT_25_1_1[2];
    tmp_0[39] = robot_simple_balancing_B.INPUT_25_1_1[3];
    tmp_1[10] = 40;
    tmp_0[40] = robot_simple_balancing_B.INPUT_26_1_1[0];
    tmp_0[41] = robot_simple_balancing_B.INPUT_26_1_1[1];
    tmp_0[42] = robot_simple_balancing_B.INPUT_26_1_1[2];
    tmp_0[43] = robot_simple_balancing_B.INPUT_26_1_1[3];
    tmp_1[11] = 44;
    tmp_0[44] = robot_simple_balancing_B.INPUT_28_1_1[0];
    tmp_0[45] = robot_simple_balancing_B.INPUT_28_1_1[1];
    tmp_0[46] = robot_simple_balancing_B.INPUT_28_1_1[2];
    tmp_0[47] = robot_simple_balancing_B.INPUT_28_1_1[3];
    tmp_1[12] = 48;
    tmp_0[48] = robot_simple_balancing_B.INPUT_31_1_1[0];
    tmp_0[49] = robot_simple_balancing_B.INPUT_31_1_1[1];
    tmp_0[50] = robot_simple_balancing_B.INPUT_31_1_1[2];
    tmp_0[51] = robot_simple_balancing_B.INPUT_31_1_1[3];
    tmp_1[13] = 52;
    tmp_0[52] = robot_simple_balancing_B.INPUT_29_1_1[0];
    tmp_0[53] = robot_simple_balancing_B.INPUT_29_1_1[1];
    tmp_0[54] = robot_simple_balancing_B.INPUT_29_1_1[2];
    tmp_0[55] = robot_simple_balancing_B.INPUT_29_1_1[3];
    tmp_1[14] = 56;
    tmp_0[56] = robot_simple_balancing_B.INPUT_30_1_1[0];
    tmp_0[57] = robot_simple_balancing_B.INPUT_30_1_1[1];
    tmp_0[58] = robot_simple_balancing_B.INPUT_30_1_1[2];
    tmp_0[59] = robot_simple_balancing_B.INPUT_30_1_1[3];
    tmp_1[15] = 60;
    tmp_0[60] = robot_simple_balancing_B.INPUT_32_1_1[0];
    tmp_0[61] = robot_simple_balancing_B.INPUT_32_1_1[1];
    tmp_0[62] = robot_simple_balancing_B.INPUT_32_1_1[2];
    tmp_0[63] = robot_simple_balancing_B.INPUT_32_1_1[3];
    tmp_1[16] = 64;
    tmp_0[64] = robot_simple_balancing_B.INPUT_35_1_1[0];
    tmp_0[65] = robot_simple_balancing_B.INPUT_35_1_1[1];
    tmp_0[66] = robot_simple_balancing_B.INPUT_35_1_1[2];
    tmp_0[67] = robot_simple_balancing_B.INPUT_35_1_1[3];
    tmp_1[17] = 68;
    tmp_0[68] = robot_simple_balancing_B.INPUT_33_1_1[0];
    tmp_0[69] = robot_simple_balancing_B.INPUT_33_1_1[1];
    tmp_0[70] = robot_simple_balancing_B.INPUT_33_1_1[2];
    tmp_0[71] = robot_simple_balancing_B.INPUT_33_1_1[3];
    tmp_1[18] = 72;
    tmp_0[72] = robot_simple_balancing_B.INPUT_34_1_1[0];
    tmp_0[73] = robot_simple_balancing_B.INPUT_34_1_1[1];
    tmp_0[74] = robot_simple_balancing_B.INPUT_34_1_1[2];
    tmp_0[75] = robot_simple_balancing_B.INPUT_34_1_1[3];
    tmp_1[19] = 76;
    tmp_0[76] = robot_simple_balancing_B.INPUT_36_1_1[0];
    tmp_0[77] = robot_simple_balancing_B.INPUT_36_1_1[1];
    tmp_0[78] = robot_simple_balancing_B.INPUT_36_1_1[2];
    tmp_0[79] = robot_simple_balancing_B.INPUT_36_1_1[3];
    tmp_1[20] = 80;
    tmp_0[80] = robot_simple_balancing_B.INPUT_8_1_1[0];
    tmp_0[81] = robot_simple_balancing_B.INPUT_8_1_1[1];
    tmp_0[82] = robot_simple_balancing_B.INPUT_8_1_1[2];
    tmp_0[83] = robot_simple_balancing_B.INPUT_8_1_1[3];
    tmp_1[21] = 84;
    tmp_0[84] = robot_simple_balancing_B.INPUT_8_1_2[0];
    tmp_0[85] = robot_simple_balancing_B.INPUT_8_1_2[1];
    tmp_0[86] = robot_simple_balancing_B.INPUT_8_1_2[2];
    tmp_0[87] = robot_simple_balancing_B.INPUT_8_1_2[3];
    tmp_1[22] = 88;
    tmp_0[88] = robot_simple_balancing_B.INPUT_8_1_3[0];
    tmp_0[89] = robot_simple_balancing_B.INPUT_8_1_3[1];
    tmp_0[90] = robot_simple_balancing_B.INPUT_8_1_3[2];
    tmp_0[91] = robot_simple_balancing_B.INPUT_8_1_3[3];
    tmp_1[23] = 92;
    tmp_0[92] = robot_simple_balancing_B.INPUT_7_1_1[0];
    tmp_0[93] = robot_simple_balancing_B.INPUT_7_1_1[1];
    tmp_0[94] = robot_simple_balancing_B.INPUT_7_1_1[2];
    tmp_0[95] = robot_simple_balancing_B.INPUT_7_1_1[3];
    tmp_1[24] = 96;
    tmp_0[96] = robot_simple_balancing_B.INPUT_7_1_2[0];
    tmp_0[97] = robot_simple_balancing_B.INPUT_7_1_2[1];
    tmp_0[98] = robot_simple_balancing_B.INPUT_7_1_2[2];
    tmp_0[99] = robot_simple_balancing_B.INPUT_7_1_2[3];
    tmp_1[25] = 100;
    tmp_0[100] = robot_simple_balancing_B.INPUT_7_1_3[0];
    tmp_0[101] = robot_simple_balancing_B.INPUT_7_1_3[1];
    tmp_0[102] = robot_simple_balancing_B.INPUT_7_1_3[2];
    tmp_0[103] = robot_simple_balancing_B.INPUT_7_1_3[3];
    tmp_1[26] = 104;
    tmp_0[104] = robot_simple_balancing_B.INPUT_5_1_1[0];
    tmp_0[105] = robot_simple_balancing_B.INPUT_5_1_1[1];
    tmp_0[106] = robot_simple_balancing_B.INPUT_5_1_1[2];
    tmp_0[107] = robot_simple_balancing_B.INPUT_5_1_1[3];
    tmp_1[27] = 108;
    tmp_0[108] = robot_simple_balancing_B.INPUT_5_1_2[0];
    tmp_0[109] = robot_simple_balancing_B.INPUT_5_1_2[1];
    tmp_0[110] = robot_simple_balancing_B.INPUT_5_1_2[2];
    tmp_0[111] = robot_simple_balancing_B.INPUT_5_1_2[3];
    tmp_1[28] = 112;
    tmp_0[112] = robot_simple_balancing_B.INPUT_5_1_3[0];
    tmp_0[113] = robot_simple_balancing_B.INPUT_5_1_3[1];
    tmp_0[114] = robot_simple_balancing_B.INPUT_5_1_3[2];
    tmp_0[115] = robot_simple_balancing_B.INPUT_5_1_3[3];
    tmp_1[29] = 116;
    tmp_0[116] = robot_simple_balancing_B.INPUT_6_1_1[0];
    tmp_0[117] = robot_simple_balancing_B.INPUT_6_1_1[1];
    tmp_0[118] = robot_simple_balancing_B.INPUT_6_1_1[2];
    tmp_0[119] = robot_simple_balancing_B.INPUT_6_1_1[3];
    tmp_1[30] = 120;
    tmp_0[120] = robot_simple_balancing_B.INPUT_6_1_2[0];
    tmp_0[121] = robot_simple_balancing_B.INPUT_6_1_2[1];
    tmp_0[122] = robot_simple_balancing_B.INPUT_6_1_2[2];
    tmp_0[123] = robot_simple_balancing_B.INPUT_6_1_2[3];
    tmp_1[31] = 124;
    tmp_0[124] = robot_simple_balancing_B.INPUT_6_1_3[0];
    tmp_0[125] = robot_simple_balancing_B.INPUT_6_1_3[1];
    tmp_0[126] = robot_simple_balancing_B.INPUT_6_1_3[2];
    tmp_0[127] = robot_simple_balancing_B.INPUT_6_1_3[3];
    tmp_1[32] = 128;
    tmp_0[128] = robot_simple_balancing_B.INPUT_12_1_1[0];
    tmp_0[129] = robot_simple_balancing_B.INPUT_12_1_1[1];
    tmp_0[130] = robot_simple_balancing_B.INPUT_12_1_1[2];
    tmp_0[131] = robot_simple_balancing_B.INPUT_12_1_1[3];
    tmp_1[33] = 132;
    tmp_0[132] = robot_simple_balancing_B.INPUT_12_1_2[0];
    tmp_0[133] = robot_simple_balancing_B.INPUT_12_1_2[1];
    tmp_0[134] = robot_simple_balancing_B.INPUT_12_1_2[2];
    tmp_0[135] = robot_simple_balancing_B.INPUT_12_1_2[3];
    tmp_1[34] = 136;
    tmp_0[136] = robot_simple_balancing_B.INPUT_12_1_3[0];
    tmp_0[137] = robot_simple_balancing_B.INPUT_12_1_3[1];
    tmp_0[138] = robot_simple_balancing_B.INPUT_12_1_3[2];
    tmp_0[139] = robot_simple_balancing_B.INPUT_12_1_3[3];
    tmp_1[35] = 140;
    tmp_0[140] = robot_simple_balancing_B.INPUT_11_1_1[0];
    tmp_0[141] = robot_simple_balancing_B.INPUT_11_1_1[1];
    tmp_0[142] = robot_simple_balancing_B.INPUT_11_1_1[2];
    tmp_0[143] = robot_simple_balancing_B.INPUT_11_1_1[3];
    tmp_1[36] = 144;
    tmp_0[144] = robot_simple_balancing_B.INPUT_11_1_2[0];
    tmp_0[145] = robot_simple_balancing_B.INPUT_11_1_2[1];
    tmp_0[146] = robot_simple_balancing_B.INPUT_11_1_2[2];
    tmp_0[147] = robot_simple_balancing_B.INPUT_11_1_2[3];
    tmp_1[37] = 148;
    tmp_0[148] = robot_simple_balancing_B.INPUT_11_1_3[0];
    tmp_0[149] = robot_simple_balancing_B.INPUT_11_1_3[1];
    tmp_0[150] = robot_simple_balancing_B.INPUT_11_1_3[2];
    tmp_0[151] = robot_simple_balancing_B.INPUT_11_1_3[3];
    tmp_1[38] = 152;
    tmp_0[152] = robot_simple_balancing_B.INPUT_9_1_1[0];
    tmp_0[153] = robot_simple_balancing_B.INPUT_9_1_1[1];
    tmp_0[154] = robot_simple_balancing_B.INPUT_9_1_1[2];
    tmp_0[155] = robot_simple_balancing_B.INPUT_9_1_1[3];
    tmp_1[39] = 156;
    tmp_0[156] = robot_simple_balancing_B.INPUT_9_1_2[0];
    tmp_0[157] = robot_simple_balancing_B.INPUT_9_1_2[1];
    tmp_0[158] = robot_simple_balancing_B.INPUT_9_1_2[2];
    tmp_0[159] = robot_simple_balancing_B.INPUT_9_1_2[3];
    tmp_1[40] = 160;
    tmp_0[160] = robot_simple_balancing_B.INPUT_9_1_3[0];
    tmp_0[161] = robot_simple_balancing_B.INPUT_9_1_3[1];
    tmp_0[162] = robot_simple_balancing_B.INPUT_9_1_3[2];
    tmp_0[163] = robot_simple_balancing_B.INPUT_9_1_3[3];
    tmp_1[41] = 164;
    tmp_0[164] = robot_simple_balancing_B.INPUT_10_1_1[0];
    tmp_0[165] = robot_simple_balancing_B.INPUT_10_1_1[1];
    tmp_0[166] = robot_simple_balancing_B.INPUT_10_1_1[2];
    tmp_0[167] = robot_simple_balancing_B.INPUT_10_1_1[3];
    tmp_1[42] = 168;
    tmp_0[168] = robot_simple_balancing_B.INPUT_10_1_2[0];
    tmp_0[169] = robot_simple_balancing_B.INPUT_10_1_2[1];
    tmp_0[170] = robot_simple_balancing_B.INPUT_10_1_2[2];
    tmp_0[171] = robot_simple_balancing_B.INPUT_10_1_2[3];
    tmp_1[43] = 172;
    tmp_0[172] = robot_simple_balancing_B.INPUT_10_1_3[0];
    tmp_0[173] = robot_simple_balancing_B.INPUT_10_1_3[1];
    tmp_0[174] = robot_simple_balancing_B.INPUT_10_1_3[2];
    tmp_0[175] = robot_simple_balancing_B.INPUT_10_1_3[3];
    tmp_1[44] = 176;
    tmp_0[176] = robot_simple_balancing_B.INPUT_16_1_1[0];
    tmp_0[177] = robot_simple_balancing_B.INPUT_16_1_1[1];
    tmp_0[178] = robot_simple_balancing_B.INPUT_16_1_1[2];
    tmp_0[179] = robot_simple_balancing_B.INPUT_16_1_1[3];
    tmp_1[45] = 180;
    tmp_0[180] = robot_simple_balancing_B.INPUT_16_1_2[0];
    tmp_0[181] = robot_simple_balancing_B.INPUT_16_1_2[1];
    tmp_0[182] = robot_simple_balancing_B.INPUT_16_1_2[2];
    tmp_0[183] = robot_simple_balancing_B.INPUT_16_1_2[3];
    tmp_1[46] = 184;
    tmp_0[184] = robot_simple_balancing_B.INPUT_16_1_3[0];
    tmp_0[185] = robot_simple_balancing_B.INPUT_16_1_3[1];
    tmp_0[186] = robot_simple_balancing_B.INPUT_16_1_3[2];
    tmp_0[187] = robot_simple_balancing_B.INPUT_16_1_3[3];
    tmp_1[47] = 188;
    tmp_0[188] = robot_simple_balancing_B.INPUT_15_1_1[0];
    tmp_0[189] = robot_simple_balancing_B.INPUT_15_1_1[1];
    tmp_0[190] = robot_simple_balancing_B.INPUT_15_1_1[2];
    tmp_0[191] = robot_simple_balancing_B.INPUT_15_1_1[3];
    tmp_1[48] = 192;
    tmp_0[192] = robot_simple_balancing_B.INPUT_15_1_2[0];
    tmp_0[193] = robot_simple_balancing_B.INPUT_15_1_2[1];
    tmp_0[194] = robot_simple_balancing_B.INPUT_15_1_2[2];
    tmp_0[195] = robot_simple_balancing_B.INPUT_15_1_2[3];
    tmp_1[49] = 196;
    tmp_0[196] = robot_simple_balancing_B.INPUT_15_1_3[0];
    tmp_0[197] = robot_simple_balancing_B.INPUT_15_1_3[1];
    tmp_0[198] = robot_simple_balancing_B.INPUT_15_1_3[2];
    tmp_0[199] = robot_simple_balancing_B.INPUT_15_1_3[3];
    tmp_1[50] = 200;
    tmp_0[200] = robot_simple_balancing_B.INPUT_13_1_1[0];
    tmp_0[201] = robot_simple_balancing_B.INPUT_13_1_1[1];
    tmp_0[202] = robot_simple_balancing_B.INPUT_13_1_1[2];
    tmp_0[203] = robot_simple_balancing_B.INPUT_13_1_1[3];
    tmp_1[51] = 204;
    tmp_0[204] = robot_simple_balancing_B.INPUT_13_1_2[0];
    tmp_0[205] = robot_simple_balancing_B.INPUT_13_1_2[1];
    tmp_0[206] = robot_simple_balancing_B.INPUT_13_1_2[2];
    tmp_0[207] = robot_simple_balancing_B.INPUT_13_1_2[3];
    tmp_1[52] = 208;
    tmp_0[208] = robot_simple_balancing_B.INPUT_13_1_3[0];
    tmp_0[209] = robot_simple_balancing_B.INPUT_13_1_3[1];
    tmp_0[210] = robot_simple_balancing_B.INPUT_13_1_3[2];
    tmp_0[211] = robot_simple_balancing_B.INPUT_13_1_3[3];
    tmp_1[53] = 212;
    tmp_0[212] = robot_simple_balancing_B.INPUT_14_1_1[0];
    tmp_0[213] = robot_simple_balancing_B.INPUT_14_1_1[1];
    tmp_0[214] = robot_simple_balancing_B.INPUT_14_1_1[2];
    tmp_0[215] = robot_simple_balancing_B.INPUT_14_1_1[3];
    tmp_1[54] = 216;
    tmp_0[216] = robot_simple_balancing_B.INPUT_14_1_2[0];
    tmp_0[217] = robot_simple_balancing_B.INPUT_14_1_2[1];
    tmp_0[218] = robot_simple_balancing_B.INPUT_14_1_2[2];
    tmp_0[219] = robot_simple_balancing_B.INPUT_14_1_2[3];
    tmp_1[55] = 220;
    tmp_0[220] = robot_simple_balancing_B.INPUT_14_1_3[0];
    tmp_0[221] = robot_simple_balancing_B.INPUT_14_1_3[1];
    tmp_0[222] = robot_simple_balancing_B.INPUT_14_1_3[2];
    tmp_0[223] = robot_simple_balancing_B.INPUT_14_1_3[3];
    tmp_1[56] = 224;
    tmp_0[224] = robot_simple_balancing_B.INPUT_20_1_1[0];
    tmp_0[225] = robot_simple_balancing_B.INPUT_20_1_1[1];
    tmp_0[226] = robot_simple_balancing_B.INPUT_20_1_1[2];
    tmp_0[227] = robot_simple_balancing_B.INPUT_20_1_1[3];
    tmp_1[57] = 228;
    tmp_0[228] = robot_simple_balancing_B.INPUT_20_1_2[0];
    tmp_0[229] = robot_simple_balancing_B.INPUT_20_1_2[1];
    tmp_0[230] = robot_simple_balancing_B.INPUT_20_1_2[2];
    tmp_0[231] = robot_simple_balancing_B.INPUT_20_1_2[3];
    tmp_1[58] = 232;
    tmp_0[232] = robot_simple_balancing_B.INPUT_20_1_3[0];
    tmp_0[233] = robot_simple_balancing_B.INPUT_20_1_3[1];
    tmp_0[234] = robot_simple_balancing_B.INPUT_20_1_3[2];
    tmp_0[235] = robot_simple_balancing_B.INPUT_20_1_3[3];
    tmp_1[59] = 236;
    tmp_0[236] = robot_simple_balancing_B.INPUT_19_1_1[0];
    tmp_0[237] = robot_simple_balancing_B.INPUT_19_1_1[1];
    tmp_0[238] = robot_simple_balancing_B.INPUT_19_1_1[2];
    tmp_0[239] = robot_simple_balancing_B.INPUT_19_1_1[3];
    tmp_1[60] = 240;
    tmp_0[240] = robot_simple_balancing_B.INPUT_19_1_2[0];
    tmp_0[241] = robot_simple_balancing_B.INPUT_19_1_2[1];
    tmp_0[242] = robot_simple_balancing_B.INPUT_19_1_2[2];
    tmp_0[243] = robot_simple_balancing_B.INPUT_19_1_2[3];
    tmp_1[61] = 244;
    tmp_0[244] = robot_simple_balancing_B.INPUT_19_1_3[0];
    tmp_0[245] = robot_simple_balancing_B.INPUT_19_1_3[1];
    tmp_0[246] = robot_simple_balancing_B.INPUT_19_1_3[2];
    tmp_0[247] = robot_simple_balancing_B.INPUT_19_1_3[3];
    tmp_1[62] = 248;
    tmp_0[248] = robot_simple_balancing_B.INPUT_17_1_1[0];
    tmp_0[249] = robot_simple_balancing_B.INPUT_17_1_1[1];
    tmp_0[250] = robot_simple_balancing_B.INPUT_17_1_1[2];
    tmp_0[251] = robot_simple_balancing_B.INPUT_17_1_1[3];
    tmp_1[63] = 252;
    tmp_0[252] = robot_simple_balancing_B.INPUT_17_1_2[0];
    tmp_0[253] = robot_simple_balancing_B.INPUT_17_1_2[1];
    tmp_0[254] = robot_simple_balancing_B.INPUT_17_1_2[2];
    tmp_0[255] = robot_simple_balancing_B.INPUT_17_1_2[3];
    tmp_1[64] = 256;
    tmp_0[256] = robot_simple_balancing_B.INPUT_17_1_3[0];
    tmp_0[257] = robot_simple_balancing_B.INPUT_17_1_3[1];
    tmp_0[258] = robot_simple_balancing_B.INPUT_17_1_3[2];
    tmp_0[259] = robot_simple_balancing_B.INPUT_17_1_3[3];
    tmp_1[65] = 260;
    tmp_0[260] = robot_simple_balancing_B.INPUT_18_1_1[0];
    tmp_0[261] = robot_simple_balancing_B.INPUT_18_1_1[1];
    tmp_0[262] = robot_simple_balancing_B.INPUT_18_1_1[2];
    tmp_0[263] = robot_simple_balancing_B.INPUT_18_1_1[3];
    tmp_1[66] = 264;
    tmp_0[264] = robot_simple_balancing_B.INPUT_18_1_2[0];
    tmp_0[265] = robot_simple_balancing_B.INPUT_18_1_2[1];
    tmp_0[266] = robot_simple_balancing_B.INPUT_18_1_2[2];
    tmp_0[267] = robot_simple_balancing_B.INPUT_18_1_2[3];
    tmp_1[67] = 268;
    tmp_0[268] = robot_simple_balancing_B.INPUT_18_1_3[0];
    tmp_0[269] = robot_simple_balancing_B.INPUT_18_1_3[1];
    tmp_0[270] = robot_simple_balancing_B.INPUT_18_1_3[2];
    tmp_0[271] = robot_simple_balancing_B.INPUT_18_1_3[3];
    tmp_1[68] = 272;
    simulationData->mData->mInputValues.mN = 272;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 69;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 13;
    simulationData->mData->mOutputs.mX = &robot_simple_balancing_B.STATE_1[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      robot_simple_balancing_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (i != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S29>/STATE_1' */

    /* SimscapeExecutionBlock: '<S29>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)
      robot_simple_balancing_DW.OUTPUT_1_0_SimData;
    time_0 = rtb_DataTypeConversion;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &robot_simple_balancing_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &robot_simple_balancing_DW.OUTPUT_1_0_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = first_output;
    first_output = false;
    simulationData->mData->mIsSolverAssertCheck = first_output;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_3[0] = 0;
    tmp_2[0] = robot_simple_balancing_B.INPUT_1_1_1[0];
    tmp_2[1] = robot_simple_balancing_B.INPUT_1_1_1[1];
    tmp_2[2] = robot_simple_balancing_B.INPUT_1_1_1[2];
    tmp_2[3] = robot_simple_balancing_B.INPUT_1_1_1[3];
    tmp_3[1] = 4;
    tmp_2[4] = robot_simple_balancing_B.INPUT_2_1_1[0];
    tmp_2[5] = robot_simple_balancing_B.INPUT_2_1_1[1];
    tmp_2[6] = robot_simple_balancing_B.INPUT_2_1_1[2];
    tmp_2[7] = robot_simple_balancing_B.INPUT_2_1_1[3];
    tmp_3[2] = 8;
    tmp_2[8] = robot_simple_balancing_B.INPUT_3_1_1[0];
    tmp_2[9] = robot_simple_balancing_B.INPUT_3_1_1[1];
    tmp_2[10] = robot_simple_balancing_B.INPUT_3_1_1[2];
    tmp_2[11] = robot_simple_balancing_B.INPUT_3_1_1[3];
    tmp_3[3] = 12;
    tmp_2[12] = robot_simple_balancing_B.INPUT_4_1_1[0];
    tmp_2[13] = robot_simple_balancing_B.INPUT_4_1_1[1];
    tmp_2[14] = robot_simple_balancing_B.INPUT_4_1_1[2];
    tmp_2[15] = robot_simple_balancing_B.INPUT_4_1_1[3];
    tmp_3[4] = 16;
    tmp_2[16] = robot_simple_balancing_B.INPUT_23_1_1[0];
    tmp_2[17] = robot_simple_balancing_B.INPUT_23_1_1[1];
    tmp_2[18] = robot_simple_balancing_B.INPUT_23_1_1[2];
    tmp_2[19] = robot_simple_balancing_B.INPUT_23_1_1[3];
    tmp_3[5] = 20;
    tmp_2[20] = robot_simple_balancing_B.INPUT_21_1_1[0];
    tmp_2[21] = robot_simple_balancing_B.INPUT_21_1_1[1];
    tmp_2[22] = robot_simple_balancing_B.INPUT_21_1_1[2];
    tmp_2[23] = robot_simple_balancing_B.INPUT_21_1_1[3];
    tmp_3[6] = 24;
    tmp_2[24] = robot_simple_balancing_B.INPUT_22_1_1[0];
    tmp_2[25] = robot_simple_balancing_B.INPUT_22_1_1[1];
    tmp_2[26] = robot_simple_balancing_B.INPUT_22_1_1[2];
    tmp_2[27] = robot_simple_balancing_B.INPUT_22_1_1[3];
    tmp_3[7] = 28;
    tmp_2[28] = robot_simple_balancing_B.INPUT_24_1_1[0];
    tmp_2[29] = robot_simple_balancing_B.INPUT_24_1_1[1];
    tmp_2[30] = robot_simple_balancing_B.INPUT_24_1_1[2];
    tmp_2[31] = robot_simple_balancing_B.INPUT_24_1_1[3];
    tmp_3[8] = 32;
    tmp_2[32] = robot_simple_balancing_B.INPUT_27_1_1[0];
    tmp_2[33] = robot_simple_balancing_B.INPUT_27_1_1[1];
    tmp_2[34] = robot_simple_balancing_B.INPUT_27_1_1[2];
    tmp_2[35] = robot_simple_balancing_B.INPUT_27_1_1[3];
    tmp_3[9] = 36;
    tmp_2[36] = robot_simple_balancing_B.INPUT_25_1_1[0];
    tmp_2[37] = robot_simple_balancing_B.INPUT_25_1_1[1];
    tmp_2[38] = robot_simple_balancing_B.INPUT_25_1_1[2];
    tmp_2[39] = robot_simple_balancing_B.INPUT_25_1_1[3];
    tmp_3[10] = 40;
    tmp_2[40] = robot_simple_balancing_B.INPUT_26_1_1[0];
    tmp_2[41] = robot_simple_balancing_B.INPUT_26_1_1[1];
    tmp_2[42] = robot_simple_balancing_B.INPUT_26_1_1[2];
    tmp_2[43] = robot_simple_balancing_B.INPUT_26_1_1[3];
    tmp_3[11] = 44;
    tmp_2[44] = robot_simple_balancing_B.INPUT_28_1_1[0];
    tmp_2[45] = robot_simple_balancing_B.INPUT_28_1_1[1];
    tmp_2[46] = robot_simple_balancing_B.INPUT_28_1_1[2];
    tmp_2[47] = robot_simple_balancing_B.INPUT_28_1_1[3];
    tmp_3[12] = 48;
    tmp_2[48] = robot_simple_balancing_B.INPUT_31_1_1[0];
    tmp_2[49] = robot_simple_balancing_B.INPUT_31_1_1[1];
    tmp_2[50] = robot_simple_balancing_B.INPUT_31_1_1[2];
    tmp_2[51] = robot_simple_balancing_B.INPUT_31_1_1[3];
    tmp_3[13] = 52;
    tmp_2[52] = robot_simple_balancing_B.INPUT_29_1_1[0];
    tmp_2[53] = robot_simple_balancing_B.INPUT_29_1_1[1];
    tmp_2[54] = robot_simple_balancing_B.INPUT_29_1_1[2];
    tmp_2[55] = robot_simple_balancing_B.INPUT_29_1_1[3];
    tmp_3[14] = 56;
    tmp_2[56] = robot_simple_balancing_B.INPUT_30_1_1[0];
    tmp_2[57] = robot_simple_balancing_B.INPUT_30_1_1[1];
    tmp_2[58] = robot_simple_balancing_B.INPUT_30_1_1[2];
    tmp_2[59] = robot_simple_balancing_B.INPUT_30_1_1[3];
    tmp_3[15] = 60;
    tmp_2[60] = robot_simple_balancing_B.INPUT_32_1_1[0];
    tmp_2[61] = robot_simple_balancing_B.INPUT_32_1_1[1];
    tmp_2[62] = robot_simple_balancing_B.INPUT_32_1_1[2];
    tmp_2[63] = robot_simple_balancing_B.INPUT_32_1_1[3];
    tmp_3[16] = 64;
    tmp_2[64] = robot_simple_balancing_B.INPUT_35_1_1[0];
    tmp_2[65] = robot_simple_balancing_B.INPUT_35_1_1[1];
    tmp_2[66] = robot_simple_balancing_B.INPUT_35_1_1[2];
    tmp_2[67] = robot_simple_balancing_B.INPUT_35_1_1[3];
    tmp_3[17] = 68;
    tmp_2[68] = robot_simple_balancing_B.INPUT_33_1_1[0];
    tmp_2[69] = robot_simple_balancing_B.INPUT_33_1_1[1];
    tmp_2[70] = robot_simple_balancing_B.INPUT_33_1_1[2];
    tmp_2[71] = robot_simple_balancing_B.INPUT_33_1_1[3];
    tmp_3[18] = 72;
    tmp_2[72] = robot_simple_balancing_B.INPUT_34_1_1[0];
    tmp_2[73] = robot_simple_balancing_B.INPUT_34_1_1[1];
    tmp_2[74] = robot_simple_balancing_B.INPUT_34_1_1[2];
    tmp_2[75] = robot_simple_balancing_B.INPUT_34_1_1[3];
    tmp_3[19] = 76;
    tmp_2[76] = robot_simple_balancing_B.INPUT_36_1_1[0];
    tmp_2[77] = robot_simple_balancing_B.INPUT_36_1_1[1];
    tmp_2[78] = robot_simple_balancing_B.INPUT_36_1_1[2];
    tmp_2[79] = robot_simple_balancing_B.INPUT_36_1_1[3];
    tmp_3[20] = 80;
    tmp_2[80] = robot_simple_balancing_B.INPUT_8_1_1[0];
    tmp_2[81] = robot_simple_balancing_B.INPUT_8_1_1[1];
    tmp_2[82] = robot_simple_balancing_B.INPUT_8_1_1[2];
    tmp_2[83] = robot_simple_balancing_B.INPUT_8_1_1[3];
    tmp_3[21] = 84;
    tmp_2[84] = robot_simple_balancing_B.INPUT_8_1_2[0];
    tmp_2[85] = robot_simple_balancing_B.INPUT_8_1_2[1];
    tmp_2[86] = robot_simple_balancing_B.INPUT_8_1_2[2];
    tmp_2[87] = robot_simple_balancing_B.INPUT_8_1_2[3];
    tmp_3[22] = 88;
    tmp_2[88] = robot_simple_balancing_B.INPUT_8_1_3[0];
    tmp_2[89] = robot_simple_balancing_B.INPUT_8_1_3[1];
    tmp_2[90] = robot_simple_balancing_B.INPUT_8_1_3[2];
    tmp_2[91] = robot_simple_balancing_B.INPUT_8_1_3[3];
    tmp_3[23] = 92;
    tmp_2[92] = robot_simple_balancing_B.INPUT_7_1_1[0];
    tmp_2[93] = robot_simple_balancing_B.INPUT_7_1_1[1];
    tmp_2[94] = robot_simple_balancing_B.INPUT_7_1_1[2];
    tmp_2[95] = robot_simple_balancing_B.INPUT_7_1_1[3];
    tmp_3[24] = 96;
    tmp_2[96] = robot_simple_balancing_B.INPUT_7_1_2[0];
    tmp_2[97] = robot_simple_balancing_B.INPUT_7_1_2[1];
    tmp_2[98] = robot_simple_balancing_B.INPUT_7_1_2[2];
    tmp_2[99] = robot_simple_balancing_B.INPUT_7_1_2[3];
    tmp_3[25] = 100;
    tmp_2[100] = robot_simple_balancing_B.INPUT_7_1_3[0];
    tmp_2[101] = robot_simple_balancing_B.INPUT_7_1_3[1];
    tmp_2[102] = robot_simple_balancing_B.INPUT_7_1_3[2];
    tmp_2[103] = robot_simple_balancing_B.INPUT_7_1_3[3];
    tmp_3[26] = 104;
    tmp_2[104] = robot_simple_balancing_B.INPUT_5_1_1[0];
    tmp_2[105] = robot_simple_balancing_B.INPUT_5_1_1[1];
    tmp_2[106] = robot_simple_balancing_B.INPUT_5_1_1[2];
    tmp_2[107] = robot_simple_balancing_B.INPUT_5_1_1[3];
    tmp_3[27] = 108;
    tmp_2[108] = robot_simple_balancing_B.INPUT_5_1_2[0];
    tmp_2[109] = robot_simple_balancing_B.INPUT_5_1_2[1];
    tmp_2[110] = robot_simple_balancing_B.INPUT_5_1_2[2];
    tmp_2[111] = robot_simple_balancing_B.INPUT_5_1_2[3];
    tmp_3[28] = 112;
    tmp_2[112] = robot_simple_balancing_B.INPUT_5_1_3[0];
    tmp_2[113] = robot_simple_balancing_B.INPUT_5_1_3[1];
    tmp_2[114] = robot_simple_balancing_B.INPUT_5_1_3[2];
    tmp_2[115] = robot_simple_balancing_B.INPUT_5_1_3[3];
    tmp_3[29] = 116;
    tmp_2[116] = robot_simple_balancing_B.INPUT_6_1_1[0];
    tmp_2[117] = robot_simple_balancing_B.INPUT_6_1_1[1];
    tmp_2[118] = robot_simple_balancing_B.INPUT_6_1_1[2];
    tmp_2[119] = robot_simple_balancing_B.INPUT_6_1_1[3];
    tmp_3[30] = 120;
    tmp_2[120] = robot_simple_balancing_B.INPUT_6_1_2[0];
    tmp_2[121] = robot_simple_balancing_B.INPUT_6_1_2[1];
    tmp_2[122] = robot_simple_balancing_B.INPUT_6_1_2[2];
    tmp_2[123] = robot_simple_balancing_B.INPUT_6_1_2[3];
    tmp_3[31] = 124;
    tmp_2[124] = robot_simple_balancing_B.INPUT_6_1_3[0];
    tmp_2[125] = robot_simple_balancing_B.INPUT_6_1_3[1];
    tmp_2[126] = robot_simple_balancing_B.INPUT_6_1_3[2];
    tmp_2[127] = robot_simple_balancing_B.INPUT_6_1_3[3];
    tmp_3[32] = 128;
    tmp_2[128] = robot_simple_balancing_B.INPUT_12_1_1[0];
    tmp_2[129] = robot_simple_balancing_B.INPUT_12_1_1[1];
    tmp_2[130] = robot_simple_balancing_B.INPUT_12_1_1[2];
    tmp_2[131] = robot_simple_balancing_B.INPUT_12_1_1[3];
    tmp_3[33] = 132;
    tmp_2[132] = robot_simple_balancing_B.INPUT_12_1_2[0];
    tmp_2[133] = robot_simple_balancing_B.INPUT_12_1_2[1];
    tmp_2[134] = robot_simple_balancing_B.INPUT_12_1_2[2];
    tmp_2[135] = robot_simple_balancing_B.INPUT_12_1_2[3];
    tmp_3[34] = 136;
    tmp_2[136] = robot_simple_balancing_B.INPUT_12_1_3[0];
    tmp_2[137] = robot_simple_balancing_B.INPUT_12_1_3[1];
    tmp_2[138] = robot_simple_balancing_B.INPUT_12_1_3[2];
    tmp_2[139] = robot_simple_balancing_B.INPUT_12_1_3[3];
    tmp_3[35] = 140;
    tmp_2[140] = robot_simple_balancing_B.INPUT_11_1_1[0];
    tmp_2[141] = robot_simple_balancing_B.INPUT_11_1_1[1];
    tmp_2[142] = robot_simple_balancing_B.INPUT_11_1_1[2];
    tmp_2[143] = robot_simple_balancing_B.INPUT_11_1_1[3];
    tmp_3[36] = 144;
    tmp_2[144] = robot_simple_balancing_B.INPUT_11_1_2[0];
    tmp_2[145] = robot_simple_balancing_B.INPUT_11_1_2[1];
    tmp_2[146] = robot_simple_balancing_B.INPUT_11_1_2[2];
    tmp_2[147] = robot_simple_balancing_B.INPUT_11_1_2[3];
    tmp_3[37] = 148;
    tmp_2[148] = robot_simple_balancing_B.INPUT_11_1_3[0];
    tmp_2[149] = robot_simple_balancing_B.INPUT_11_1_3[1];
    tmp_2[150] = robot_simple_balancing_B.INPUT_11_1_3[2];
    tmp_2[151] = robot_simple_balancing_B.INPUT_11_1_3[3];
    tmp_3[38] = 152;
    tmp_2[152] = robot_simple_balancing_B.INPUT_9_1_1[0];
    tmp_2[153] = robot_simple_balancing_B.INPUT_9_1_1[1];
    tmp_2[154] = robot_simple_balancing_B.INPUT_9_1_1[2];
    tmp_2[155] = robot_simple_balancing_B.INPUT_9_1_1[3];
    tmp_3[39] = 156;
    tmp_2[156] = robot_simple_balancing_B.INPUT_9_1_2[0];
    tmp_2[157] = robot_simple_balancing_B.INPUT_9_1_2[1];
    tmp_2[158] = robot_simple_balancing_B.INPUT_9_1_2[2];
    tmp_2[159] = robot_simple_balancing_B.INPUT_9_1_2[3];
    tmp_3[40] = 160;
    tmp_2[160] = robot_simple_balancing_B.INPUT_9_1_3[0];
    tmp_2[161] = robot_simple_balancing_B.INPUT_9_1_3[1];
    tmp_2[162] = robot_simple_balancing_B.INPUT_9_1_3[2];
    tmp_2[163] = robot_simple_balancing_B.INPUT_9_1_3[3];
    tmp_3[41] = 164;
    tmp_2[164] = robot_simple_balancing_B.INPUT_10_1_1[0];
    tmp_2[165] = robot_simple_balancing_B.INPUT_10_1_1[1];
    tmp_2[166] = robot_simple_balancing_B.INPUT_10_1_1[2];
    tmp_2[167] = robot_simple_balancing_B.INPUT_10_1_1[3];
    tmp_3[42] = 168;
    tmp_2[168] = robot_simple_balancing_B.INPUT_10_1_2[0];
    tmp_2[169] = robot_simple_balancing_B.INPUT_10_1_2[1];
    tmp_2[170] = robot_simple_balancing_B.INPUT_10_1_2[2];
    tmp_2[171] = robot_simple_balancing_B.INPUT_10_1_2[3];
    tmp_3[43] = 172;
    tmp_2[172] = robot_simple_balancing_B.INPUT_10_1_3[0];
    tmp_2[173] = robot_simple_balancing_B.INPUT_10_1_3[1];
    tmp_2[174] = robot_simple_balancing_B.INPUT_10_1_3[2];
    tmp_2[175] = robot_simple_balancing_B.INPUT_10_1_3[3];
    tmp_3[44] = 176;
    tmp_2[176] = robot_simple_balancing_B.INPUT_16_1_1[0];
    tmp_2[177] = robot_simple_balancing_B.INPUT_16_1_1[1];
    tmp_2[178] = robot_simple_balancing_B.INPUT_16_1_1[2];
    tmp_2[179] = robot_simple_balancing_B.INPUT_16_1_1[3];
    tmp_3[45] = 180;
    tmp_2[180] = robot_simple_balancing_B.INPUT_16_1_2[0];
    tmp_2[181] = robot_simple_balancing_B.INPUT_16_1_2[1];
    tmp_2[182] = robot_simple_balancing_B.INPUT_16_1_2[2];
    tmp_2[183] = robot_simple_balancing_B.INPUT_16_1_2[3];
    tmp_3[46] = 184;
    tmp_2[184] = robot_simple_balancing_B.INPUT_16_1_3[0];
    tmp_2[185] = robot_simple_balancing_B.INPUT_16_1_3[1];
    tmp_2[186] = robot_simple_balancing_B.INPUT_16_1_3[2];
    tmp_2[187] = robot_simple_balancing_B.INPUT_16_1_3[3];
    tmp_3[47] = 188;
    tmp_2[188] = robot_simple_balancing_B.INPUT_15_1_1[0];
    tmp_2[189] = robot_simple_balancing_B.INPUT_15_1_1[1];
    tmp_2[190] = robot_simple_balancing_B.INPUT_15_1_1[2];
    tmp_2[191] = robot_simple_balancing_B.INPUT_15_1_1[3];
    tmp_3[48] = 192;
    tmp_2[192] = robot_simple_balancing_B.INPUT_15_1_2[0];
    tmp_2[193] = robot_simple_balancing_B.INPUT_15_1_2[1];
    tmp_2[194] = robot_simple_balancing_B.INPUT_15_1_2[2];
    tmp_2[195] = robot_simple_balancing_B.INPUT_15_1_2[3];
    tmp_3[49] = 196;
    tmp_2[196] = robot_simple_balancing_B.INPUT_15_1_3[0];
    tmp_2[197] = robot_simple_balancing_B.INPUT_15_1_3[1];
    tmp_2[198] = robot_simple_balancing_B.INPUT_15_1_3[2];
    tmp_2[199] = robot_simple_balancing_B.INPUT_15_1_3[3];
    tmp_3[50] = 200;
    tmp_2[200] = robot_simple_balancing_B.INPUT_13_1_1[0];
    tmp_2[201] = robot_simple_balancing_B.INPUT_13_1_1[1];
    tmp_2[202] = robot_simple_balancing_B.INPUT_13_1_1[2];
    tmp_2[203] = robot_simple_balancing_B.INPUT_13_1_1[3];
    tmp_3[51] = 204;
    tmp_2[204] = robot_simple_balancing_B.INPUT_13_1_2[0];
    tmp_2[205] = robot_simple_balancing_B.INPUT_13_1_2[1];
    tmp_2[206] = robot_simple_balancing_B.INPUT_13_1_2[2];
    tmp_2[207] = robot_simple_balancing_B.INPUT_13_1_2[3];
    tmp_3[52] = 208;
    tmp_2[208] = robot_simple_balancing_B.INPUT_13_1_3[0];
    tmp_2[209] = robot_simple_balancing_B.INPUT_13_1_3[1];
    tmp_2[210] = robot_simple_balancing_B.INPUT_13_1_3[2];
    tmp_2[211] = robot_simple_balancing_B.INPUT_13_1_3[3];
    tmp_3[53] = 212;
    tmp_2[212] = robot_simple_balancing_B.INPUT_14_1_1[0];
    tmp_2[213] = robot_simple_balancing_B.INPUT_14_1_1[1];
    tmp_2[214] = robot_simple_balancing_B.INPUT_14_1_1[2];
    tmp_2[215] = robot_simple_balancing_B.INPUT_14_1_1[3];
    tmp_3[54] = 216;
    tmp_2[216] = robot_simple_balancing_B.INPUT_14_1_2[0];
    tmp_2[217] = robot_simple_balancing_B.INPUT_14_1_2[1];
    tmp_2[218] = robot_simple_balancing_B.INPUT_14_1_2[2];
    tmp_2[219] = robot_simple_balancing_B.INPUT_14_1_2[3];
    tmp_3[55] = 220;
    tmp_2[220] = robot_simple_balancing_B.INPUT_14_1_3[0];
    tmp_2[221] = robot_simple_balancing_B.INPUT_14_1_3[1];
    tmp_2[222] = robot_simple_balancing_B.INPUT_14_1_3[2];
    tmp_2[223] = robot_simple_balancing_B.INPUT_14_1_3[3];
    tmp_3[56] = 224;
    tmp_2[224] = robot_simple_balancing_B.INPUT_20_1_1[0];
    tmp_2[225] = robot_simple_balancing_B.INPUT_20_1_1[1];
    tmp_2[226] = robot_simple_balancing_B.INPUT_20_1_1[2];
    tmp_2[227] = robot_simple_balancing_B.INPUT_20_1_1[3];
    tmp_3[57] = 228;
    tmp_2[228] = robot_simple_balancing_B.INPUT_20_1_2[0];
    tmp_2[229] = robot_simple_balancing_B.INPUT_20_1_2[1];
    tmp_2[230] = robot_simple_balancing_B.INPUT_20_1_2[2];
    tmp_2[231] = robot_simple_balancing_B.INPUT_20_1_2[3];
    tmp_3[58] = 232;
    tmp_2[232] = robot_simple_balancing_B.INPUT_20_1_3[0];
    tmp_2[233] = robot_simple_balancing_B.INPUT_20_1_3[1];
    tmp_2[234] = robot_simple_balancing_B.INPUT_20_1_3[2];
    tmp_2[235] = robot_simple_balancing_B.INPUT_20_1_3[3];
    tmp_3[59] = 236;
    tmp_2[236] = robot_simple_balancing_B.INPUT_19_1_1[0];
    tmp_2[237] = robot_simple_balancing_B.INPUT_19_1_1[1];
    tmp_2[238] = robot_simple_balancing_B.INPUT_19_1_1[2];
    tmp_2[239] = robot_simple_balancing_B.INPUT_19_1_1[3];
    tmp_3[60] = 240;
    tmp_2[240] = robot_simple_balancing_B.INPUT_19_1_2[0];
    tmp_2[241] = robot_simple_balancing_B.INPUT_19_1_2[1];
    tmp_2[242] = robot_simple_balancing_B.INPUT_19_1_2[2];
    tmp_2[243] = robot_simple_balancing_B.INPUT_19_1_2[3];
    tmp_3[61] = 244;
    tmp_2[244] = robot_simple_balancing_B.INPUT_19_1_3[0];
    tmp_2[245] = robot_simple_balancing_B.INPUT_19_1_3[1];
    tmp_2[246] = robot_simple_balancing_B.INPUT_19_1_3[2];
    tmp_2[247] = robot_simple_balancing_B.INPUT_19_1_3[3];
    tmp_3[62] = 248;
    tmp_2[248] = robot_simple_balancing_B.INPUT_17_1_1[0];
    tmp_2[249] = robot_simple_balancing_B.INPUT_17_1_1[1];
    tmp_2[250] = robot_simple_balancing_B.INPUT_17_1_1[2];
    tmp_2[251] = robot_simple_balancing_B.INPUT_17_1_1[3];
    tmp_3[63] = 252;
    tmp_2[252] = robot_simple_balancing_B.INPUT_17_1_2[0];
    tmp_2[253] = robot_simple_balancing_B.INPUT_17_1_2[1];
    tmp_2[254] = robot_simple_balancing_B.INPUT_17_1_2[2];
    tmp_2[255] = robot_simple_balancing_B.INPUT_17_1_2[3];
    tmp_3[64] = 256;
    tmp_2[256] = robot_simple_balancing_B.INPUT_17_1_3[0];
    tmp_2[257] = robot_simple_balancing_B.INPUT_17_1_3[1];
    tmp_2[258] = robot_simple_balancing_B.INPUT_17_1_3[2];
    tmp_2[259] = robot_simple_balancing_B.INPUT_17_1_3[3];
    tmp_3[65] = 260;
    tmp_2[260] = robot_simple_balancing_B.INPUT_18_1_1[0];
    tmp_2[261] = robot_simple_balancing_B.INPUT_18_1_1[1];
    tmp_2[262] = robot_simple_balancing_B.INPUT_18_1_1[2];
    tmp_2[263] = robot_simple_balancing_B.INPUT_18_1_1[3];
    tmp_3[66] = 264;
    tmp_2[264] = robot_simple_balancing_B.INPUT_18_1_2[0];
    tmp_2[265] = robot_simple_balancing_B.INPUT_18_1_2[1];
    tmp_2[266] = robot_simple_balancing_B.INPUT_18_1_2[2];
    tmp_2[267] = robot_simple_balancing_B.INPUT_18_1_2[3];
    tmp_3[67] = 268;
    tmp_2[268] = robot_simple_balancing_B.INPUT_18_1_3[0];
    tmp_2[269] = robot_simple_balancing_B.INPUT_18_1_3[1];
    tmp_2[270] = robot_simple_balancing_B.INPUT_18_1_3[2];
    tmp_2[271] = robot_simple_balancing_B.INPUT_18_1_3[3];
    tmp_3[68] = 272;
    memcpy(&tmp_2[272], &robot_simple_balancing_B.STATE_1[0], 13U * sizeof
           (real_T));
    tmp_3[69] = 285;
    simulationData->mData->mInputValues.mN = 285;
    simulationData->mData->mInputValues.mX = &tmp_2[0];
    simulationData->mData->mInputOffsets.mN = 70;
    simulationData->mData->mInputOffsets.mX = &tmp_3[0];
    simulationData->mData->mOutputs.mN = 80;
    simulationData->mData->mOutputs.mX = &robot_simple_balancing_B.OUTPUT_1_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    i = ne_simulator_method((NeslSimulator *)
      robot_simple_balancing_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diagnosticManager);
    if (i != 0) {
      first_output = error_buffer_is_empty(rtmGetErrorStatus
        (robot_simple_balancing_M));
      if (first_output) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    /* Gain: '<S30>/Gain' */
    rtb_DataTypeConversion = robot_simple_balancing_P.Gain_Gain_mp *
      robot_simple_balancing_B.OUTPUT_1_0[11];

    /* Abs: '<S30>/Abs' */
    rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

    /* Gain: '<S30>/Gain1' */
    rtb_Abs1 = robot_simple_balancing_P.Gain1_Gain *
      robot_simple_balancing_B.OUTPUT_1_0[12];

    /* Abs: '<S30>/Abs1' */
    rtb_Abs1 = fabs(rtb_Abs1);

    /* If: '<S12>/If1' incorporates:
     *  Constant: '<S34>/Zeros'
     *  Constant: '<S36>/Constant'
     *  Constant: '<S37>/Constant'
     *  Logic: '<S30>/Logical Operator'
     *  RelationalOperator: '<S36>/Compare'
     *  RelationalOperator: '<S37>/Compare'
     *  Sum: '<S33>/Sum1'
     */
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      rtAction = (int8_T)((!(rtb_DataTypeConversion <
        robot_simple_balancing_P.SpheretoPlaneForceFR_plane_lenx)) ||
                          (!(rtb_Abs1 <
        robot_simple_balancing_P.SpheretoPlaneForceFR_plane_leny)));
      robot_simple_balancing_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = robot_simple_balancing_DW.If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S12>/Forces' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Abs: '<S46>/Abs' */
      rtb_DataTypeConversion = fabs(robot_simple_balancing_B.OUTPUT_1_0[13]);

      /* Sum: '<S46>/Sum' incorporates:
       *  Constant: '<S46>/Constant'
       */
      rtb_DataTypeConversion =
        (robot_simple_balancing_P.SpheretoPlaneForceFR_sphere_rad +
         robot_simple_balancing_P.SpheretoPlaneForceFR_plane_dept) -
        rtb_DataTypeConversion;

      /* DeadZone: '<S46>/Dead Zone' */
      if (rtb_DataTypeConversion > robot_simple_balancing_P.DeadZone_End) {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_End;
      } else if (rtb_DataTypeConversion >=
                 robot_simple_balancing_P.DeadZone_Start) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_Start;
      }

      /* End of DeadZone: '<S46>/Dead Zone' */

      /* Signum: '<S46>/Sign x' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[13];
      if (rtb_Product_as < 0.0) {
        rtb_Signx_e = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Signx_e = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Signx_e = 0.0;
      } else {
        rtb_Signx_e = (rtNaN);
      }

      /* End of Signum: '<S46>/Sign x' */

      /* Product: '<S46>/Product' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[16];

      /* Gain: '<S46>/Gain2' */
      rtb_Abs1 *= robot_simple_balancing_P.Gain2_Gain;

      /* Signum: '<S46>/Sign vx' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[16];

      /* Product: '<S33>/Product' incorporates:
       *  Gain: '<S55>/Gain1'
       */
      rtb_SprForce_d = robot_simple_balancing_P.c_k * rtb_DataTypeConversion *
        rtb_Signx_e;

      /* Signum: '<S55>/Sign' */
      if (rtb_DataTypeConversion < 0.0) {
        rtb_DataTypeConversion = -1.0;
      } else if (rtb_DataTypeConversion > 0.0) {
        rtb_DataTypeConversion = 1.0;
      } else if (rtb_DataTypeConversion == 0.0) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion = (rtNaN);
      }

      /* End of Signum: '<S55>/Sign' */

      /* Abs: '<S55>/Abs' */
      rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

      /* Saturate: '<S55>/Saturation' */
      if (rtb_Abs1 > robot_simple_balancing_P.Saturation_UpperSat) {
        rtb_Abs1 = robot_simple_balancing_P.Saturation_UpperSat;
      } else {
        if (rtb_Abs1 < robot_simple_balancing_P.Saturation_LowerSat) {
          rtb_Abs1 = robot_simple_balancing_P.Saturation_LowerSat;
        }
      }

      /* End of Saturate: '<S55>/Saturation' */

      /* SignalConversion generated from: '<S49>/Product2' incorporates:
       *  Constant: '<S49>/Fx'
       */
      p_new[0] = robot_simple_balancing_P.Fx_Value;
      p_new[1] = robot_simple_balancing_P.Fx_Value;

      /* Signum: '<S46>/Sign vx' */
      if (rtb_Product_as < 0.0) {
        rtb_Product_as = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Product_as = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Product_as = 0.0;
      } else {
        rtb_Product_as = (rtNaN);
      }

      /* SignalConversion generated from: '<S49>/Product2' incorporates:
       *  Gain: '<S55>/Gain2'
       *  Product: '<S33>/Product1'
       *  Product: '<S55>/Product'
       *  Sum: '<S49>/Sum'
       */
      p_new[2] = -robot_simple_balancing_P.c_b * rtb_Abs1 *
        rtb_DataTypeConversion * rtb_Product_as + rtb_SprForce_d;

      /* Gain: '<S49>/Gain' */
      rtb_Product1_cj[2] = robot_simple_balancing_P.Gain_Gain * p_new[2];

      /* Product: '<S53>/Product3' incorporates:
       *  Constant: '<S53>/Fx1'
       */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[9] *
        robot_simple_balancing_P.SpheretoPlaneForceFR_sphere_rad;

      /* Product: '<S48>/Product5' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[15];

      /* Sum: '<S53>/Sum1' */
      rtb_Product_as += rtb_Abs1;

      /* Product: '<S53>/Product4' incorporates:
       *  Constant: '<S53>/Fx1'
       */
      rtb_Abs1 = robot_simple_balancing_P.SpheretoPlaneForceFR_sphere_rad *
        robot_simple_balancing_B.OUTPUT_1_0[10];

      /* Product: '<S48>/Product6' */
      rtb_DataTypeConversion = robot_simple_balancing_B.OUTPUT_1_0[14] *
        rtb_Signx_e;

      /* Sum: '<S53>/Sum2' */
      rtb_Abs1 = rtb_DataTypeConversion - rtb_Abs1;

      /* Gain: '<S54>/Gain2' incorporates:
       *  Lookup_n-D: '<S54>/Coefficient of Friction vs Velocity'
       *  Math: '<S53>/Math Function'
       *  Math: '<S53>/Math Function1'
       *  Product: '<S54>/Product'
       *  Sqrt: '<S53>/Sqrt'
       *  Sum: '<S53>/Sum3'
       */
      rtb_DataTypeConversion = look1_binlxpw(sqrt(rtb_Product_as *
        rtb_Product_as + rtb_Abs1 * rtb_Abs1),
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_h,
        robot_simple_balancing_P.CoefficientofFrictionvsVelocity, 5U) *
        rtb_Product1_cj[2] * robot_simple_balancing_P.Gain2_Gain_g;

      /* Trigonometry: '<S53>/Trigonometric Function' */
      rtb_Product_as = rt_atan2d_snf(rtb_Product_as, rtb_Abs1);

      /* Product: '<S48>/Product3' incorporates:
       *  Trigonometry: '<S48>/Trigonometric Function1'
       */
      rtb_Abs1 = rtb_DataTypeConversion * cos(rtb_Product_as);

      /* Product: '<S48>/Product4' incorporates:
       *  Trigonometry: '<S48>/Trigonometric Function'
       */
      rtb_DataTypeConversion *= sin(rtb_Product_as);

      /* SignalConversion generated from: '<S48>/Product1' incorporates:
       *  Constant: '<S48>/Fx1'
       */
      rtb_TmpSignalConversionAtProd_d[0] = rtb_Abs1;
      rtb_TmpSignalConversionAtProd_d[1] = rtb_DataTypeConversion;
      rtb_TmpSignalConversionAtProd_d[2] = robot_simple_balancing_P.Fx1_Value;

      /* Gain: '<S49>/Gain' incorporates:
       *  Constant: '<S49>/Fx'
       */
      rtb_Product_as = robot_simple_balancing_P.Gain_Gain *
        robot_simple_balancing_P.Fx_Value;

      /* Sum: '<S33>/Sum1' incorporates:
       *  Gain: '<S48>/Gain'
       *  Gain: '<S49>/Gain'
       *  SignalConversion generated from: '<S48>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_i *
        rtb_Abs1;

      /* SignalConversion: '<S33>/Copy for Merge' */
      robot_simple_balancing_B.FSph[6] = rtb_SprForce_d;
      rtb_Product1_cj[0] = rtb_SprForce_d;

      /* Sum: '<S33>/Sum1' incorporates:
       *  Gain: '<S48>/Gain'
       *  SignalConversion generated from: '<S48>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_i *
        rtb_DataTypeConversion;

      /* SignalConversion: '<S33>/Copy for Merge' */
      robot_simple_balancing_B.FSph[7] = rtb_SprForce_d;
      rtb_Product1_cj[1] = rtb_SprForce_d;

      /* Sum: '<S33>/Sum1' incorporates:
       *  Constant: '<S48>/Fx1'
       *  Gain: '<S48>/Gain'
       */
      rtb_SprForce_d = robot_simple_balancing_P.Gain_Gain_i *
        robot_simple_balancing_P.Fx1_Value + rtb_Product1_cj[2];

      /* SignalConversion: '<S33>/Copy for Merge' */
      robot_simple_balancing_B.FSph[8] = rtb_SprForce_d;

      /* Product: '<S47>/Product' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[12] * rtb_SprForce_d;

      /* Product: '<S47>/Product1' */
      rtb_Product1_o = robot_simple_balancing_B.OUTPUT_1_0[13] *
        rtb_Product1_cj[1];

      /* Product: '<S47>/Product2' */
      rtb_Product3_j = robot_simple_balancing_B.OUTPUT_1_0[13] *
        rtb_Product1_cj[0];

      /* Product: '<S47>/Product3' */
      rtb_SprForce_d *= robot_simple_balancing_B.OUTPUT_1_0[11];

      /* Product: '<S47>/Product4' */
      rtb_Product1_bz = robot_simple_balancing_B.OUTPUT_1_0[11] *
        rtb_Product1_cj[1];

      /* Product: '<S47>/Product5' */
      rtb_Product_m = robot_simple_balancing_B.OUTPUT_1_0[12] * rtb_Product1_cj
        [0];

      /* Sum: '<S47>/Sum' */
      robot_simple_balancing_B.FSph[9] = rtb_Product_as - rtb_Product1_o;

      /* Sum: '<S47>/Sum1' */
      robot_simple_balancing_B.FSph[10] = rtb_Product3_j - rtb_SprForce_d;

      /* Sum: '<S47>/Sum2' */
      robot_simple_balancing_B.FSph[11] = rtb_Product1_bz - rtb_Product_m;

      /* Product: '<S48>/Product7' incorporates:
       *  Constant: '<S48>/Fx2'
       */
      rtb_Product1_cj[0] = robot_simple_balancing_P.Fx2_Value[0] * rtb_Signx_e;
      rtb_Product1_cj[1] = robot_simple_balancing_P.Fx2_Value[1] * rtb_Signx_e;
      rtb_Product1_cj[2] = robot_simple_balancing_P.Fx2_Value[2] * rtb_Signx_e;

      /* Product: '<S51>/Product1' */
      rtb_Product1_bz = rtb_Product1_cj[2] * rtb_DataTypeConversion;

      /* Product: '<S51>/Product2' */
      rtb_SprForce_d = rtb_Product1_cj[2] * rtb_Abs1;

      /* Product: '<S51>/Product4' */
      rtb_DataTypeConversion *= rtb_Product1_cj[0];

      /* Product: '<S51>/Product5' */
      rtb_Abs1 *= rtb_Product1_cj[1];

      /* SignalConversion generated from: '<S48>/Product2' incorporates:
       *  Constant: '<S48>/Fx1'
       *  Product: '<S51>/Product'
       *  Product: '<S51>/Product3'
       *  Sum: '<S51>/Sum'
       *  Sum: '<S51>/Sum1'
       */
      rtb_Signx_p_2[0] = rtb_Product1_cj[1] * robot_simple_balancing_P.Fx1_Value
        - rtb_Product1_bz;
      rtb_Signx_p_2[1] = rtb_SprForce_d - rtb_Product1_cj[0] *
        robot_simple_balancing_P.Fx1_Value;

      /* Product: '<S48>/Product1' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[0],
        rtb_TmpSignalConversionAtProd_d, rtb_Product1_cj);

      /* SignalConversion generated from: '<S48>/Product2' incorporates:
       *  Sum: '<S51>/Sum2'
       */
      rtb_Signx_p_2[2] = rtb_DataTypeConversion - rtb_Abs1;

      /* Product: '<S48>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[0],
        rtb_Signx_p_2, &robot_simple_balancing_B.FSph[3]);

      /* Product: '<S49>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[0],
        p_new, rtb_TmpSignalConversionAtProd_d);

      /* Sum: '<S33>/Sum' */
      robot_simple_balancing_B.FSph[0] = rtb_TmpSignalConversionAtProd_d[0] +
        rtb_Product1_cj[0];
      robot_simple_balancing_B.FSph[1] = rtb_TmpSignalConversionAtProd_d[1] +
        rtb_Product1_cj[1];
      robot_simple_balancing_B.FSph[2] = rtb_TmpSignalConversionAtProd_d[2] +
        rtb_Product1_cj[2];

      /* End of Outputs for SubSystem: '<S12>/Forces' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S12>/No Force' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
        memcpy(&robot_simple_balancing_B.FSph[0],
               &robot_simple_balancing_P.Zeros_Value[0], 12U * sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S12>/No Force' */
      break;
    }

    /* End of If: '<S12>/If1' */

    /* Gain: '<S74>/Gain' */
    rtb_DataTypeConversion = robot_simple_balancing_P.Gain_Gain_a *
      robot_simple_balancing_B.OUTPUT_1_0[28];

    /* Abs: '<S74>/Abs' */
    rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

    /* Gain: '<S74>/Gain1' */
    rtb_Abs1 = robot_simple_balancing_P.Gain1_Gain_e *
      robot_simple_balancing_B.OUTPUT_1_0[29];

    /* Abs: '<S74>/Abs1' */
    rtb_Abs1 = fabs(rtb_Abs1);

    /* If: '<S13>/If1' incorporates:
     *  Constant: '<S78>/Zeros'
     *  Constant: '<S80>/Constant'
     *  Constant: '<S81>/Constant'
     *  Logic: '<S74>/Logical Operator'
     *  RelationalOperator: '<S80>/Compare'
     *  RelationalOperator: '<S81>/Compare'
     *  Sum: '<S77>/Sum1'
     */
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      rtAction = (int8_T)((!(rtb_DataTypeConversion <
        robot_simple_balancing_P.SpheretoPlaneForceFR1_plane_len)) ||
                          (!(rtb_Abs1 <
        robot_simple_balancing_P.SpheretoPlaneForceFR1_plane_l_j)));
      robot_simple_balancing_DW.If1_ActiveSubsystem_p = rtAction;
    } else {
      rtAction = robot_simple_balancing_DW.If1_ActiveSubsystem_p;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S13>/Forces' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      /* Abs: '<S90>/Abs' */
      rtb_DataTypeConversion = fabs(robot_simple_balancing_B.OUTPUT_1_0[30]);

      /* Sum: '<S90>/Sum' incorporates:
       *  Constant: '<S90>/Constant'
       */
      rtb_DataTypeConversion =
        (robot_simple_balancing_P.SpheretoPlaneForceFR1_sphere_ra +
         robot_simple_balancing_P.SpheretoPlaneForceFR1_plane_dep) -
        rtb_DataTypeConversion;

      /* DeadZone: '<S90>/Dead Zone' */
      if (rtb_DataTypeConversion > robot_simple_balancing_P.DeadZone_End_j) {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_End_j;
      } else if (rtb_DataTypeConversion >=
                 robot_simple_balancing_P.DeadZone_Start_i) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_Start_i;
      }

      /* End of DeadZone: '<S90>/Dead Zone' */

      /* Signum: '<S90>/Sign x' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[30];
      if (rtb_Product_as < 0.0) {
        rtb_Signx_e = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Signx_e = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Signx_e = 0.0;
      } else {
        rtb_Signx_e = (rtNaN);
      }

      /* End of Signum: '<S90>/Sign x' */

      /* Product: '<S90>/Product' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[33];

      /* Gain: '<S90>/Gain2' */
      rtb_Abs1 *= robot_simple_balancing_P.Gain2_Gain_k;

      /* Signum: '<S90>/Sign vx' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[33];

      /* Product: '<S77>/Product' incorporates:
       *  Gain: '<S99>/Gain1'
       */
      rtb_SprForce_d = robot_simple_balancing_P.c_k * rtb_DataTypeConversion *
        rtb_Signx_e;

      /* Signum: '<S99>/Sign' */
      if (rtb_DataTypeConversion < 0.0) {
        rtb_DataTypeConversion = -1.0;
      } else if (rtb_DataTypeConversion > 0.0) {
        rtb_DataTypeConversion = 1.0;
      } else if (rtb_DataTypeConversion == 0.0) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion = (rtNaN);
      }

      /* End of Signum: '<S99>/Sign' */

      /* Abs: '<S99>/Abs' */
      rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

      /* Saturate: '<S99>/Saturation' */
      if (rtb_Abs1 > robot_simple_balancing_P.Saturation_UpperSat_b) {
        rtb_Abs1 = robot_simple_balancing_P.Saturation_UpperSat_b;
      } else {
        if (rtb_Abs1 < robot_simple_balancing_P.Saturation_LowerSat_m) {
          rtb_Abs1 = robot_simple_balancing_P.Saturation_LowerSat_m;
        }
      }

      /* End of Saturate: '<S99>/Saturation' */

      /* SignalConversion generated from: '<S93>/Product2' incorporates:
       *  Constant: '<S93>/Fx'
       */
      p_new[0] = robot_simple_balancing_P.Fx_Value_a;
      p_new[1] = robot_simple_balancing_P.Fx_Value_a;

      /* Signum: '<S90>/Sign vx' */
      if (rtb_Product_as < 0.0) {
        rtb_Product_as = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Product_as = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Product_as = 0.0;
      } else {
        rtb_Product_as = (rtNaN);
      }

      /* SignalConversion generated from: '<S93>/Product2' incorporates:
       *  Gain: '<S99>/Gain2'
       *  Product: '<S77>/Product1'
       *  Product: '<S99>/Product'
       *  Sum: '<S93>/Sum'
       */
      p_new[2] = -robot_simple_balancing_P.c_b * rtb_Abs1 *
        rtb_DataTypeConversion * rtb_Product_as + rtb_SprForce_d;

      /* Gain: '<S93>/Gain' */
      rtb_Product1_cj[2] = robot_simple_balancing_P.Gain_Gain_o * p_new[2];

      /* Product: '<S97>/Product3' incorporates:
       *  Constant: '<S97>/Fx1'
       */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[26] *
        robot_simple_balancing_P.SpheretoPlaneForceFR1_sphere_ra;

      /* Product: '<S92>/Product5' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[32];

      /* Sum: '<S97>/Sum1' */
      rtb_Product_as += rtb_Abs1;

      /* Product: '<S97>/Product4' incorporates:
       *  Constant: '<S97>/Fx1'
       */
      rtb_Abs1 = robot_simple_balancing_P.SpheretoPlaneForceFR1_sphere_ra *
        robot_simple_balancing_B.OUTPUT_1_0[27];

      /* Product: '<S92>/Product6' */
      rtb_DataTypeConversion = robot_simple_balancing_B.OUTPUT_1_0[31] *
        rtb_Signx_e;

      /* Sum: '<S97>/Sum2' */
      rtb_Abs1 = rtb_DataTypeConversion - rtb_Abs1;

      /* Gain: '<S98>/Gain2' incorporates:
       *  Lookup_n-D: '<S98>/Coefficient of Friction vs Velocity'
       *  Math: '<S97>/Math Function'
       *  Math: '<S97>/Math Function1'
       *  Product: '<S98>/Product'
       *  Sqrt: '<S97>/Sqrt'
       *  Sum: '<S97>/Sum3'
       */
      rtb_DataTypeConversion = look1_binlxpw(sqrt(rtb_Product_as *
        rtb_Product_as + rtb_Abs1 * rtb_Abs1),
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_f,
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_g, 5U) *
        rtb_Product1_cj[2] * robot_simple_balancing_P.Gain2_Gain_o;

      /* Trigonometry: '<S97>/Trigonometric Function' */
      rtb_Product_as = rt_atan2d_snf(rtb_Product_as, rtb_Abs1);

      /* Product: '<S92>/Product3' incorporates:
       *  Trigonometry: '<S92>/Trigonometric Function1'
       */
      rtb_Abs1 = rtb_DataTypeConversion * cos(rtb_Product_as);

      /* Product: '<S92>/Product4' incorporates:
       *  Trigonometry: '<S92>/Trigonometric Function'
       */
      rtb_DataTypeConversion *= sin(rtb_Product_as);

      /* SignalConversion generated from: '<S92>/Product1' incorporates:
       *  Constant: '<S92>/Fx1'
       */
      rtb_TmpSignalConversionAtProd_d[0] = rtb_Abs1;
      rtb_TmpSignalConversionAtProd_d[1] = rtb_DataTypeConversion;
      rtb_TmpSignalConversionAtProd_d[2] = robot_simple_balancing_P.Fx1_Value_d;

      /* Gain: '<S93>/Gain' incorporates:
       *  Constant: '<S93>/Fx'
       */
      rtb_Product_as = robot_simple_balancing_P.Gain_Gain_o *
        robot_simple_balancing_P.Fx_Value_a;

      /* Sum: '<S77>/Sum1' incorporates:
       *  Gain: '<S92>/Gain'
       *  Gain: '<S93>/Gain'
       *  SignalConversion generated from: '<S92>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_m *
        rtb_Abs1;

      /* SignalConversion: '<S77>/Copy for Merge' */
      robot_simple_balancing_B.FSph_f[6] = rtb_SprForce_d;
      rtb_Product1_cj[0] = rtb_SprForce_d;

      /* Sum: '<S77>/Sum1' incorporates:
       *  Gain: '<S92>/Gain'
       *  SignalConversion generated from: '<S92>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_m *
        rtb_DataTypeConversion;

      /* SignalConversion: '<S77>/Copy for Merge' */
      robot_simple_balancing_B.FSph_f[7] = rtb_SprForce_d;
      rtb_Product1_cj[1] = rtb_SprForce_d;

      /* Sum: '<S77>/Sum1' incorporates:
       *  Constant: '<S92>/Fx1'
       *  Gain: '<S92>/Gain'
       */
      rtb_SprForce_d = robot_simple_balancing_P.Gain_Gain_m *
        robot_simple_balancing_P.Fx1_Value_d + rtb_Product1_cj[2];

      /* SignalConversion: '<S77>/Copy for Merge' */
      robot_simple_balancing_B.FSph_f[8] = rtb_SprForce_d;

      /* Product: '<S91>/Product' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[29] * rtb_SprForce_d;

      /* Product: '<S91>/Product1' */
      rtb_Product1_o = robot_simple_balancing_B.OUTPUT_1_0[30] *
        rtb_Product1_cj[1];

      /* Product: '<S91>/Product2' */
      rtb_Product3_j = robot_simple_balancing_B.OUTPUT_1_0[30] *
        rtb_Product1_cj[0];

      /* Product: '<S91>/Product3' */
      rtb_SprForce_d *= robot_simple_balancing_B.OUTPUT_1_0[28];

      /* Product: '<S91>/Product4' */
      rtb_Product1_bz = robot_simple_balancing_B.OUTPUT_1_0[28] *
        rtb_Product1_cj[1];

      /* Product: '<S91>/Product5' */
      rtb_Product_m = robot_simple_balancing_B.OUTPUT_1_0[29] * rtb_Product1_cj
        [0];

      /* Sum: '<S91>/Sum' */
      robot_simple_balancing_B.FSph_f[9] = rtb_Product_as - rtb_Product1_o;

      /* Sum: '<S91>/Sum1' */
      robot_simple_balancing_B.FSph_f[10] = rtb_Product3_j - rtb_SprForce_d;

      /* Sum: '<S91>/Sum2' */
      robot_simple_balancing_B.FSph_f[11] = rtb_Product1_bz - rtb_Product_m;

      /* Product: '<S92>/Product7' incorporates:
       *  Constant: '<S92>/Fx2'
       */
      rtb_Product1_cj[0] = robot_simple_balancing_P.Fx2_Value_e[0] * rtb_Signx_e;
      rtb_Product1_cj[1] = robot_simple_balancing_P.Fx2_Value_e[1] * rtb_Signx_e;
      rtb_Product1_cj[2] = robot_simple_balancing_P.Fx2_Value_e[2] * rtb_Signx_e;

      /* Product: '<S95>/Product1' */
      rtb_Product1_bz = rtb_Product1_cj[2] * rtb_DataTypeConversion;

      /* Product: '<S95>/Product2' */
      rtb_SprForce_d = rtb_Product1_cj[2] * rtb_Abs1;

      /* Product: '<S95>/Product4' */
      rtb_DataTypeConversion *= rtb_Product1_cj[0];

      /* Product: '<S95>/Product5' */
      rtb_Abs1 *= rtb_Product1_cj[1];

      /* SignalConversion generated from: '<S92>/Product2' incorporates:
       *  Constant: '<S92>/Fx1'
       *  Product: '<S95>/Product'
       *  Product: '<S95>/Product3'
       *  Sum: '<S95>/Sum'
       *  Sum: '<S95>/Sum1'
       */
      rtb_Signx_p_1[0] = rtb_Product1_cj[1] *
        robot_simple_balancing_P.Fx1_Value_d - rtb_Product1_bz;
      rtb_Signx_p_1[1] = rtb_SprForce_d - rtb_Product1_cj[0] *
        robot_simple_balancing_P.Fx1_Value_d;

      /* Product: '<S92>/Product1' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[17],
        rtb_TmpSignalConversionAtProd_d, rtb_Product1_cj);

      /* SignalConversion generated from: '<S92>/Product2' incorporates:
       *  Sum: '<S95>/Sum2'
       */
      rtb_Signx_p_1[2] = rtb_DataTypeConversion - rtb_Abs1;

      /* Product: '<S92>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[17],
        rtb_Signx_p_1, &robot_simple_balancing_B.FSph_f[3]);

      /* Product: '<S93>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[17],
        p_new, rtb_TmpSignalConversionAtProd_d);

      /* Sum: '<S77>/Sum' */
      robot_simple_balancing_B.FSph_f[0] = rtb_TmpSignalConversionAtProd_d[0] +
        rtb_Product1_cj[0];
      robot_simple_balancing_B.FSph_f[1] = rtb_TmpSignalConversionAtProd_d[1] +
        rtb_Product1_cj[1];
      robot_simple_balancing_B.FSph_f[2] = rtb_TmpSignalConversionAtProd_d[2] +
        rtb_Product1_cj[2];

      /* End of Outputs for SubSystem: '<S13>/Forces' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S13>/No Force' incorporates:
       *  ActionPort: '<S78>/Action Port'
       */
      if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
        memcpy(&robot_simple_balancing_B.FSph_f[0],
               &robot_simple_balancing_P.Zeros_Value_k[0], 12U * sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S13>/No Force' */
      break;
    }

    /* End of If: '<S13>/If1' */

    /* Gain: '<S118>/Gain' */
    rtb_DataTypeConversion = robot_simple_balancing_P.Gain_Gain_ln *
      robot_simple_balancing_B.OUTPUT_1_0[45];

    /* Abs: '<S118>/Abs' */
    rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

    /* Gain: '<S118>/Gain1' */
    rtb_Abs1 = robot_simple_balancing_P.Gain1_Gain_k *
      robot_simple_balancing_B.OUTPUT_1_0[46];

    /* Abs: '<S118>/Abs1' */
    rtb_Abs1 = fabs(rtb_Abs1);

    /* If: '<S14>/If1' incorporates:
     *  Constant: '<S122>/Zeros'
     *  Constant: '<S124>/Constant'
     *  Constant: '<S125>/Constant'
     *  Logic: '<S118>/Logical Operator'
     *  RelationalOperator: '<S124>/Compare'
     *  RelationalOperator: '<S125>/Compare'
     *  Sum: '<S121>/Sum1'
     */
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      rtAction = (int8_T)((!(rtb_DataTypeConversion <
        robot_simple_balancing_P.SpheretoPlaneForceFR2_plane_len)) ||
                          (!(rtb_Abs1 <
        robot_simple_balancing_P.SpheretoPlaneForceFR2_plane_l_g)));
      robot_simple_balancing_DW.If1_ActiveSubsystem_e = rtAction;
    } else {
      rtAction = robot_simple_balancing_DW.If1_ActiveSubsystem_e;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S14>/Forces' incorporates:
       *  ActionPort: '<S121>/Action Port'
       */
      /* Abs: '<S134>/Abs' */
      rtb_DataTypeConversion = fabs(robot_simple_balancing_B.OUTPUT_1_0[47]);

      /* Sum: '<S134>/Sum' incorporates:
       *  Constant: '<S134>/Constant'
       */
      rtb_DataTypeConversion =
        (robot_simple_balancing_P.SpheretoPlaneForceFR2_sphere_ra +
         robot_simple_balancing_P.SpheretoPlaneForceFR2_plane_dep) -
        rtb_DataTypeConversion;

      /* DeadZone: '<S134>/Dead Zone' */
      if (rtb_DataTypeConversion > robot_simple_balancing_P.DeadZone_End_p) {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_End_p;
      } else if (rtb_DataTypeConversion >=
                 robot_simple_balancing_P.DeadZone_Start_e) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_Start_e;
      }

      /* End of DeadZone: '<S134>/Dead Zone' */

      /* Signum: '<S134>/Sign x' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[47];
      if (rtb_Product_as < 0.0) {
        rtb_Signx_e = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Signx_e = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Signx_e = 0.0;
      } else {
        rtb_Signx_e = (rtNaN);
      }

      /* End of Signum: '<S134>/Sign x' */

      /* Product: '<S134>/Product' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[50];

      /* Gain: '<S134>/Gain2' */
      rtb_Abs1 *= robot_simple_balancing_P.Gain2_Gain_h;

      /* Signum: '<S134>/Sign vx' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[50];

      /* Product: '<S121>/Product' incorporates:
       *  Gain: '<S143>/Gain1'
       */
      rtb_SprForce_d = robot_simple_balancing_P.c_k * rtb_DataTypeConversion *
        rtb_Signx_e;

      /* Signum: '<S143>/Sign' */
      if (rtb_DataTypeConversion < 0.0) {
        rtb_DataTypeConversion = -1.0;
      } else if (rtb_DataTypeConversion > 0.0) {
        rtb_DataTypeConversion = 1.0;
      } else if (rtb_DataTypeConversion == 0.0) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion = (rtNaN);
      }

      /* End of Signum: '<S143>/Sign' */

      /* Abs: '<S143>/Abs' */
      rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

      /* Saturate: '<S143>/Saturation' */
      if (rtb_Abs1 > robot_simple_balancing_P.Saturation_UpperSat_j) {
        rtb_Abs1 = robot_simple_balancing_P.Saturation_UpperSat_j;
      } else {
        if (rtb_Abs1 < robot_simple_balancing_P.Saturation_LowerSat_o) {
          rtb_Abs1 = robot_simple_balancing_P.Saturation_LowerSat_o;
        }
      }

      /* End of Saturate: '<S143>/Saturation' */

      /* SignalConversion generated from: '<S137>/Product2' incorporates:
       *  Constant: '<S137>/Fx'
       */
      p_new[0] = robot_simple_balancing_P.Fx_Value_d;
      p_new[1] = robot_simple_balancing_P.Fx_Value_d;

      /* Signum: '<S134>/Sign vx' */
      if (rtb_Product_as < 0.0) {
        rtb_Product_as = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Product_as = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Product_as = 0.0;
      } else {
        rtb_Product_as = (rtNaN);
      }

      /* SignalConversion generated from: '<S137>/Product2' incorporates:
       *  Gain: '<S143>/Gain2'
       *  Product: '<S121>/Product1'
       *  Product: '<S143>/Product'
       *  Sum: '<S137>/Sum'
       */
      p_new[2] = -robot_simple_balancing_P.c_b * rtb_Abs1 *
        rtb_DataTypeConversion * rtb_Product_as + rtb_SprForce_d;

      /* Gain: '<S137>/Gain' */
      rtb_Product1_cj[2] = robot_simple_balancing_P.Gain_Gain_d * p_new[2];

      /* Product: '<S141>/Product3' incorporates:
       *  Constant: '<S141>/Fx1'
       */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[43] *
        robot_simple_balancing_P.SpheretoPlaneForceFR2_sphere_ra;

      /* Product: '<S136>/Product5' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[49];

      /* Sum: '<S141>/Sum1' */
      rtb_Product_as += rtb_Abs1;

      /* Product: '<S141>/Product4' incorporates:
       *  Constant: '<S141>/Fx1'
       */
      rtb_Abs1 = robot_simple_balancing_P.SpheretoPlaneForceFR2_sphere_ra *
        robot_simple_balancing_B.OUTPUT_1_0[44];

      /* Product: '<S136>/Product6' */
      rtb_DataTypeConversion = robot_simple_balancing_B.OUTPUT_1_0[48] *
        rtb_Signx_e;

      /* Sum: '<S141>/Sum2' */
      rtb_Abs1 = rtb_DataTypeConversion - rtb_Abs1;

      /* Gain: '<S142>/Gain2' incorporates:
       *  Lookup_n-D: '<S142>/Coefficient of Friction vs Velocity'
       *  Math: '<S141>/Math Function'
       *  Math: '<S141>/Math Function1'
       *  Product: '<S142>/Product'
       *  Sqrt: '<S141>/Sqrt'
       *  Sum: '<S141>/Sum3'
       */
      rtb_DataTypeConversion = look1_binlxpw(sqrt(rtb_Product_as *
        rtb_Product_as + rtb_Abs1 * rtb_Abs1),
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_m,
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_n, 5U) *
        rtb_Product1_cj[2] * robot_simple_balancing_P.Gain2_Gain_a;

      /* Trigonometry: '<S141>/Trigonometric Function' */
      rtb_Product_as = rt_atan2d_snf(rtb_Product_as, rtb_Abs1);

      /* Product: '<S136>/Product3' incorporates:
       *  Trigonometry: '<S136>/Trigonometric Function1'
       */
      rtb_Abs1 = rtb_DataTypeConversion * cos(rtb_Product_as);

      /* Product: '<S136>/Product4' incorporates:
       *  Trigonometry: '<S136>/Trigonometric Function'
       */
      rtb_DataTypeConversion *= sin(rtb_Product_as);

      /* SignalConversion generated from: '<S136>/Product1' incorporates:
       *  Constant: '<S136>/Fx1'
       */
      rtb_TmpSignalConversionAtProd_d[0] = rtb_Abs1;
      rtb_TmpSignalConversionAtProd_d[1] = rtb_DataTypeConversion;
      rtb_TmpSignalConversionAtProd_d[2] = robot_simple_balancing_P.Fx1_Value_k;

      /* Gain: '<S137>/Gain' incorporates:
       *  Constant: '<S137>/Fx'
       */
      rtb_Product_as = robot_simple_balancing_P.Gain_Gain_d *
        robot_simple_balancing_P.Fx_Value_d;

      /* Sum: '<S121>/Sum1' incorporates:
       *  Gain: '<S136>/Gain'
       *  Gain: '<S137>/Gain'
       *  SignalConversion generated from: '<S136>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_d1 *
        rtb_Abs1;

      /* SignalConversion: '<S121>/Copy for Merge' */
      robot_simple_balancing_B.FSph_n[6] = rtb_SprForce_d;
      rtb_Product1_cj[0] = rtb_SprForce_d;

      /* Sum: '<S121>/Sum1' incorporates:
       *  Gain: '<S136>/Gain'
       *  SignalConversion generated from: '<S136>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_d1 *
        rtb_DataTypeConversion;

      /* SignalConversion: '<S121>/Copy for Merge' */
      robot_simple_balancing_B.FSph_n[7] = rtb_SprForce_d;
      rtb_Product1_cj[1] = rtb_SprForce_d;

      /* Sum: '<S121>/Sum1' incorporates:
       *  Constant: '<S136>/Fx1'
       *  Gain: '<S136>/Gain'
       */
      rtb_SprForce_d = robot_simple_balancing_P.Gain_Gain_d1 *
        robot_simple_balancing_P.Fx1_Value_k + rtb_Product1_cj[2];

      /* SignalConversion: '<S121>/Copy for Merge' */
      robot_simple_balancing_B.FSph_n[8] = rtb_SprForce_d;

      /* Product: '<S135>/Product' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[46] * rtb_SprForce_d;

      /* Product: '<S135>/Product1' */
      rtb_Product1_o = robot_simple_balancing_B.OUTPUT_1_0[47] *
        rtb_Product1_cj[1];

      /* Product: '<S135>/Product2' */
      rtb_Product3_j = robot_simple_balancing_B.OUTPUT_1_0[47] *
        rtb_Product1_cj[0];

      /* Product: '<S135>/Product3' */
      rtb_SprForce_d *= robot_simple_balancing_B.OUTPUT_1_0[45];

      /* Product: '<S135>/Product4' */
      rtb_Product1_bz = robot_simple_balancing_B.OUTPUT_1_0[45] *
        rtb_Product1_cj[1];

      /* Product: '<S135>/Product5' */
      rtb_Product_m = robot_simple_balancing_B.OUTPUT_1_0[46] * rtb_Product1_cj
        [0];

      /* Sum: '<S135>/Sum' */
      robot_simple_balancing_B.FSph_n[9] = rtb_Product_as - rtb_Product1_o;

      /* Sum: '<S135>/Sum1' */
      robot_simple_balancing_B.FSph_n[10] = rtb_Product3_j - rtb_SprForce_d;

      /* Sum: '<S135>/Sum2' */
      robot_simple_balancing_B.FSph_n[11] = rtb_Product1_bz - rtb_Product_m;

      /* Product: '<S136>/Product7' incorporates:
       *  Constant: '<S136>/Fx2'
       */
      rtb_Product1_cj[0] = robot_simple_balancing_P.Fx2_Value_m[0] * rtb_Signx_e;
      rtb_Product1_cj[1] = robot_simple_balancing_P.Fx2_Value_m[1] * rtb_Signx_e;
      rtb_Product1_cj[2] = robot_simple_balancing_P.Fx2_Value_m[2] * rtb_Signx_e;

      /* Product: '<S139>/Product1' */
      rtb_Product1_bz = rtb_Product1_cj[2] * rtb_DataTypeConversion;

      /* Product: '<S139>/Product2' */
      rtb_SprForce_d = rtb_Product1_cj[2] * rtb_Abs1;

      /* Product: '<S139>/Product4' */
      rtb_DataTypeConversion *= rtb_Product1_cj[0];

      /* Product: '<S139>/Product5' */
      rtb_Abs1 *= rtb_Product1_cj[1];

      /* SignalConversion generated from: '<S136>/Product2' incorporates:
       *  Constant: '<S136>/Fx1'
       *  Product: '<S139>/Product'
       *  Product: '<S139>/Product3'
       *  Sum: '<S139>/Sum'
       *  Sum: '<S139>/Sum1'
       */
      rtb_Signx_p_0[0] = rtb_Product1_cj[1] *
        robot_simple_balancing_P.Fx1_Value_k - rtb_Product1_bz;
      rtb_Signx_p_0[1] = rtb_SprForce_d - rtb_Product1_cj[0] *
        robot_simple_balancing_P.Fx1_Value_k;

      /* Product: '<S136>/Product1' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[34],
        rtb_TmpSignalConversionAtProd_d, rtb_Product1_cj);

      /* SignalConversion generated from: '<S136>/Product2' incorporates:
       *  Sum: '<S139>/Sum2'
       */
      rtb_Signx_p_0[2] = rtb_DataTypeConversion - rtb_Abs1;

      /* Product: '<S136>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[34],
        rtb_Signx_p_0, &robot_simple_balancing_B.FSph_n[3]);

      /* Product: '<S137>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[34],
        p_new, rtb_TmpSignalConversionAtProd_d);

      /* Sum: '<S121>/Sum' */
      robot_simple_balancing_B.FSph_n[0] = rtb_TmpSignalConversionAtProd_d[0] +
        rtb_Product1_cj[0];
      robot_simple_balancing_B.FSph_n[1] = rtb_TmpSignalConversionAtProd_d[1] +
        rtb_Product1_cj[1];
      robot_simple_balancing_B.FSph_n[2] = rtb_TmpSignalConversionAtProd_d[2] +
        rtb_Product1_cj[2];

      /* End of Outputs for SubSystem: '<S14>/Forces' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S14>/No Force' incorporates:
       *  ActionPort: '<S122>/Action Port'
       */
      if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
        memcpy(&robot_simple_balancing_B.FSph_n[0],
               &robot_simple_balancing_P.Zeros_Value_m[0], 12U * sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S14>/No Force' */
      break;
    }

    /* End of If: '<S14>/If1' */

    /* Gain: '<S162>/Gain' */
    rtb_DataTypeConversion = robot_simple_balancing_P.Gain_Gain_h *
      robot_simple_balancing_B.OUTPUT_1_0[62];

    /* Abs: '<S162>/Abs' */
    rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

    /* Gain: '<S162>/Gain1' */
    rtb_Abs1 = robot_simple_balancing_P.Gain1_Gain_c *
      robot_simple_balancing_B.OUTPUT_1_0[63];

    /* Abs: '<S162>/Abs1' */
    rtb_Abs1 = fabs(rtb_Abs1);

    /* If: '<S15>/If1' incorporates:
     *  Constant: '<S166>/Zeros'
     *  Constant: '<S168>/Constant'
     *  Constant: '<S169>/Constant'
     *  Logic: '<S162>/Logical Operator'
     *  RelationalOperator: '<S168>/Compare'
     *  RelationalOperator: '<S169>/Compare'
     *  Sum: '<S165>/Sum1'
     */
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      rtAction = (int8_T)((!(rtb_DataTypeConversion <
        robot_simple_balancing_P.SpheretoPlaneForceFR3_plane_len)) ||
                          (!(rtb_Abs1 <
        robot_simple_balancing_P.SpheretoPlaneForceFR3_plane_l_e)));
      robot_simple_balancing_DW.If1_ActiveSubsystem_a = rtAction;
    } else {
      rtAction = robot_simple_balancing_DW.If1_ActiveSubsystem_a;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S15>/Forces' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      /* Abs: '<S178>/Abs' */
      rtb_DataTypeConversion = fabs(robot_simple_balancing_B.OUTPUT_1_0[64]);

      /* Sum: '<S178>/Sum' incorporates:
       *  Constant: '<S178>/Constant'
       */
      rtb_DataTypeConversion =
        (robot_simple_balancing_P.SpheretoPlaneForceFR3_sphere_ra +
         robot_simple_balancing_P.SpheretoPlaneForceFR3_plane_dep) -
        rtb_DataTypeConversion;

      /* DeadZone: '<S178>/Dead Zone' */
      if (rtb_DataTypeConversion > robot_simple_balancing_P.DeadZone_End_ps) {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_End_ps;
      } else if (rtb_DataTypeConversion >=
                 robot_simple_balancing_P.DeadZone_Start_f) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion -= robot_simple_balancing_P.DeadZone_Start_f;
      }

      /* End of DeadZone: '<S178>/Dead Zone' */

      /* Signum: '<S178>/Sign x' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[64];
      if (rtb_Product_as < 0.0) {
        rtb_Signx_e = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Signx_e = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Signx_e = 0.0;
      } else {
        rtb_Signx_e = (rtNaN);
      }

      /* End of Signum: '<S178>/Sign x' */

      /* Product: '<S178>/Product' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[67];

      /* Gain: '<S178>/Gain2' */
      rtb_Abs1 *= robot_simple_balancing_P.Gain2_Gain_e;

      /* Signum: '<S178>/Sign vx' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[67];

      /* Product: '<S165>/Product' incorporates:
       *  Gain: '<S187>/Gain1'
       */
      rtb_SprForce_d = robot_simple_balancing_P.c_k * rtb_DataTypeConversion *
        rtb_Signx_e;

      /* Signum: '<S187>/Sign' */
      if (rtb_DataTypeConversion < 0.0) {
        rtb_DataTypeConversion = -1.0;
      } else if (rtb_DataTypeConversion > 0.0) {
        rtb_DataTypeConversion = 1.0;
      } else if (rtb_DataTypeConversion == 0.0) {
        rtb_DataTypeConversion = 0.0;
      } else {
        rtb_DataTypeConversion = (rtNaN);
      }

      /* End of Signum: '<S187>/Sign' */

      /* Abs: '<S187>/Abs' */
      rtb_DataTypeConversion = fabs(rtb_DataTypeConversion);

      /* Saturate: '<S187>/Saturation' */
      if (rtb_Abs1 > robot_simple_balancing_P.Saturation_UpperSat_k) {
        rtb_Abs1 = robot_simple_balancing_P.Saturation_UpperSat_k;
      } else {
        if (rtb_Abs1 < robot_simple_balancing_P.Saturation_LowerSat_op) {
          rtb_Abs1 = robot_simple_balancing_P.Saturation_LowerSat_op;
        }
      }

      /* End of Saturate: '<S187>/Saturation' */

      /* SignalConversion generated from: '<S181>/Product2' incorporates:
       *  Constant: '<S181>/Fx'
       */
      p_new[0] = robot_simple_balancing_P.Fx_Value_c;
      p_new[1] = robot_simple_balancing_P.Fx_Value_c;

      /* Signum: '<S178>/Sign vx' */
      if (rtb_Product_as < 0.0) {
        rtb_Product_as = -1.0;
      } else if (rtb_Product_as > 0.0) {
        rtb_Product_as = 1.0;
      } else if (rtb_Product_as == 0.0) {
        rtb_Product_as = 0.0;
      } else {
        rtb_Product_as = (rtNaN);
      }

      /* SignalConversion generated from: '<S181>/Product2' incorporates:
       *  Gain: '<S187>/Gain2'
       *  Product: '<S165>/Product1'
       *  Product: '<S187>/Product'
       *  Sum: '<S181>/Sum'
       */
      p_new[2] = -robot_simple_balancing_P.c_b * rtb_Abs1 *
        rtb_DataTypeConversion * rtb_Product_as + rtb_SprForce_d;

      /* Gain: '<S181>/Gain' */
      rtb_Product1_cj[2] = robot_simple_balancing_P.Gain_Gain_l * p_new[2];

      /* Product: '<S185>/Product3' incorporates:
       *  Constant: '<S185>/Fx1'
       */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[60] *
        robot_simple_balancing_P.SpheretoPlaneForceFR3_sphere_ra;

      /* Product: '<S180>/Product5' */
      rtb_Abs1 = rtb_Signx_e * robot_simple_balancing_B.OUTPUT_1_0[66];

      /* Sum: '<S185>/Sum1' */
      rtb_Product_as += rtb_Abs1;

      /* Product: '<S185>/Product4' incorporates:
       *  Constant: '<S185>/Fx1'
       */
      rtb_Abs1 = robot_simple_balancing_P.SpheretoPlaneForceFR3_sphere_ra *
        robot_simple_balancing_B.OUTPUT_1_0[61];

      /* Product: '<S180>/Product6' */
      rtb_DataTypeConversion = robot_simple_balancing_B.OUTPUT_1_0[65] *
        rtb_Signx_e;

      /* Sum: '<S185>/Sum2' */
      rtb_Abs1 = rtb_DataTypeConversion - rtb_Abs1;

      /* Gain: '<S186>/Gain2' incorporates:
       *  Lookup_n-D: '<S186>/Coefficient of Friction vs Velocity'
       *  Math: '<S185>/Math Function'
       *  Math: '<S185>/Math Function1'
       *  Product: '<S186>/Product'
       *  Sqrt: '<S185>/Sqrt'
       *  Sum: '<S185>/Sum3'
       */
      rtb_DataTypeConversion = look1_binlxpw(sqrt(rtb_Product_as *
        rtb_Product_as + rtb_Abs1 * rtb_Abs1),
        robot_simple_balancing_P.CoefficientofFrictionvsVeloc_my,
        robot_simple_balancing_P.CoefficientofFrictionvsVeloci_e, 5U) *
        rtb_Product1_cj[2] * robot_simple_balancing_P.Gain2_Gain_j;

      /* Trigonometry: '<S185>/Trigonometric Function' */
      rtb_Product_as = rt_atan2d_snf(rtb_Product_as, rtb_Abs1);

      /* Product: '<S180>/Product3' incorporates:
       *  Trigonometry: '<S180>/Trigonometric Function1'
       */
      rtb_Abs1 = rtb_DataTypeConversion * cos(rtb_Product_as);

      /* Product: '<S180>/Product4' incorporates:
       *  Trigonometry: '<S180>/Trigonometric Function'
       */
      rtb_DataTypeConversion *= sin(rtb_Product_as);

      /* SignalConversion generated from: '<S180>/Product1' incorporates:
       *  Constant: '<S180>/Fx1'
       */
      rtb_TmpSignalConversionAtProd_d[0] = rtb_Abs1;
      rtb_TmpSignalConversionAtProd_d[1] = rtb_DataTypeConversion;
      rtb_TmpSignalConversionAtProd_d[2] = robot_simple_balancing_P.Fx1_Value_g;

      /* Gain: '<S181>/Gain' incorporates:
       *  Constant: '<S181>/Fx'
       */
      rtb_Product_as = robot_simple_balancing_P.Gain_Gain_l *
        robot_simple_balancing_P.Fx_Value_c;

      /* Sum: '<S165>/Sum1' incorporates:
       *  Gain: '<S180>/Gain'
       *  Gain: '<S181>/Gain'
       *  SignalConversion generated from: '<S180>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_c *
        rtb_Abs1;

      /* SignalConversion: '<S165>/Copy for Merge' */
      robot_simple_balancing_B.FSph_fe[6] = rtb_SprForce_d;
      rtb_Product1_cj[0] = rtb_SprForce_d;

      /* Sum: '<S165>/Sum1' incorporates:
       *  Gain: '<S180>/Gain'
       *  SignalConversion generated from: '<S180>/Product1'
       */
      rtb_SprForce_d = rtb_Product_as + robot_simple_balancing_P.Gain_Gain_c *
        rtb_DataTypeConversion;

      /* SignalConversion: '<S165>/Copy for Merge' */
      robot_simple_balancing_B.FSph_fe[7] = rtb_SprForce_d;
      rtb_Product1_cj[1] = rtb_SprForce_d;

      /* Sum: '<S165>/Sum1' incorporates:
       *  Constant: '<S180>/Fx1'
       *  Gain: '<S180>/Gain'
       */
      rtb_SprForce_d = robot_simple_balancing_P.Gain_Gain_c *
        robot_simple_balancing_P.Fx1_Value_g + rtb_Product1_cj[2];

      /* SignalConversion: '<S165>/Copy for Merge' */
      robot_simple_balancing_B.FSph_fe[8] = rtb_SprForce_d;

      /* Product: '<S179>/Product' */
      rtb_Product_as = robot_simple_balancing_B.OUTPUT_1_0[63] * rtb_SprForce_d;

      /* Product: '<S179>/Product1' */
      rtb_Product1_o = robot_simple_balancing_B.OUTPUT_1_0[64] *
        rtb_Product1_cj[1];

      /* Product: '<S179>/Product2' */
      rtb_Product3_j = robot_simple_balancing_B.OUTPUT_1_0[64] *
        rtb_Product1_cj[0];

      /* Product: '<S179>/Product3' */
      rtb_SprForce_d *= robot_simple_balancing_B.OUTPUT_1_0[62];

      /* Product: '<S179>/Product4' */
      rtb_Product1_bz = robot_simple_balancing_B.OUTPUT_1_0[62] *
        rtb_Product1_cj[1];

      /* Product: '<S179>/Product5' */
      rtb_Product_m = robot_simple_balancing_B.OUTPUT_1_0[63] * rtb_Product1_cj
        [0];

      /* Sum: '<S179>/Sum' */
      robot_simple_balancing_B.FSph_fe[9] = rtb_Product_as - rtb_Product1_o;

      /* Sum: '<S179>/Sum1' */
      robot_simple_balancing_B.FSph_fe[10] = rtb_Product3_j - rtb_SprForce_d;

      /* Sum: '<S179>/Sum2' */
      robot_simple_balancing_B.FSph_fe[11] = rtb_Product1_bz - rtb_Product_m;

      /* Product: '<S180>/Product7' incorporates:
       *  Constant: '<S180>/Fx2'
       */
      rtb_Product1_cj[0] = robot_simple_balancing_P.Fx2_Value_j[0] * rtb_Signx_e;
      rtb_Product1_cj[1] = robot_simple_balancing_P.Fx2_Value_j[1] * rtb_Signx_e;
      rtb_Product1_cj[2] = robot_simple_balancing_P.Fx2_Value_j[2] * rtb_Signx_e;

      /* Product: '<S183>/Product1' */
      rtb_Product1_bz = rtb_Product1_cj[2] * rtb_DataTypeConversion;

      /* Product: '<S183>/Product2' */
      rtb_SprForce_d = rtb_Product1_cj[2] * rtb_Abs1;

      /* Product: '<S183>/Product4' */
      rtb_DataTypeConversion *= rtb_Product1_cj[0];

      /* Product: '<S183>/Product5' */
      rtb_Abs1 *= rtb_Product1_cj[1];

      /* SignalConversion generated from: '<S180>/Product2' incorporates:
       *  Constant: '<S180>/Fx1'
       *  Product: '<S183>/Product'
       *  Product: '<S183>/Product3'
       *  Sum: '<S183>/Sum'
       *  Sum: '<S183>/Sum1'
       */
      rtb_Signx_p[0] = rtb_Product1_cj[1] * robot_simple_balancing_P.Fx1_Value_g
        - rtb_Product1_bz;
      rtb_Signx_p[1] = rtb_SprForce_d - rtb_Product1_cj[0] *
        robot_simple_balancing_P.Fx1_Value_g;

      /* Product: '<S180>/Product1' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[51],
        rtb_TmpSignalConversionAtProd_d, rtb_Product1_cj);

      /* SignalConversion generated from: '<S180>/Product2' incorporates:
       *  Sum: '<S183>/Sum2'
       */
      rtb_Signx_p[2] = rtb_DataTypeConversion - rtb_Abs1;

      /* Product: '<S180>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[51],
        rtb_Signx_p, &robot_simple_balancing_B.FSph_fe[3]);

      /* Product: '<S181>/Product2' */
      rt_mldivide_U1d3x3_U2d_9O8lG8ax(&robot_simple_balancing_B.OUTPUT_1_0[51],
        p_new, rtb_TmpSignalConversionAtProd_d);

      /* Sum: '<S165>/Sum' */
      robot_simple_balancing_B.FSph_fe[0] = rtb_TmpSignalConversionAtProd_d[0] +
        rtb_Product1_cj[0];
      robot_simple_balancing_B.FSph_fe[1] = rtb_TmpSignalConversionAtProd_d[1] +
        rtb_Product1_cj[1];
      robot_simple_balancing_B.FSph_fe[2] = rtb_TmpSignalConversionAtProd_d[2] +
        rtb_Product1_cj[2];

      /* End of Outputs for SubSystem: '<S15>/Forces' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S15>/No Force' incorporates:
       *  ActionPort: '<S166>/Action Port'
       */
      if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
        memcpy(&robot_simple_balancing_B.FSph_fe[0],
               &robot_simple_balancing_P.Zeros_Value_f[0], 12U * sizeof(real_T));
      }

      /* End of Outputs for SubSystem: '<S15>/No Force' */
      break;
    }

    /* End of If: '<S15>/If1' */
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
    }

    /* SimscapeInputBlock: '<S29>/INPUT_8_1_1' */
    robot_simple_balancing_B.INPUT_8_1_1[0] = robot_simple_balancing_B.FSph[6];
    robot_simple_balancing_B.INPUT_8_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_8_1_2' */
    robot_simple_balancing_B.INPUT_8_1_2[0] = robot_simple_balancing_B.FSph[7];
    robot_simple_balancing_B.INPUT_8_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_8_1_3' */
    robot_simple_balancing_B.INPUT_8_1_3[0] = robot_simple_balancing_B.FSph[8];
    robot_simple_balancing_B.INPUT_8_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_8_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_7_1_1' */
    robot_simple_balancing_B.INPUT_7_1_1[0] = robot_simple_balancing_B.FSph[9];
    robot_simple_balancing_B.INPUT_7_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_7_1_2' */
    robot_simple_balancing_B.INPUT_7_1_2[0] = robot_simple_balancing_B.FSph[10];
    robot_simple_balancing_B.INPUT_7_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_7_1_3' */
    robot_simple_balancing_B.INPUT_7_1_3[0] = robot_simple_balancing_B.FSph[11];
    robot_simple_balancing_B.INPUT_7_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_7_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_5_1_1' */
    robot_simple_balancing_B.INPUT_5_1_1[0] = robot_simple_balancing_B.FSph[0];
    robot_simple_balancing_B.INPUT_5_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_5_1_2' */
    robot_simple_balancing_B.INPUT_5_1_2[0] = robot_simple_balancing_B.FSph[1];
    robot_simple_balancing_B.INPUT_5_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_5_1_3' */
    robot_simple_balancing_B.INPUT_5_1_3[0] = robot_simple_balancing_B.FSph[2];
    robot_simple_balancing_B.INPUT_5_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_5_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_6_1_1' */
    robot_simple_balancing_B.INPUT_6_1_1[0] = robot_simple_balancing_B.FSph[3];
    robot_simple_balancing_B.INPUT_6_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_6_1_2' */
    robot_simple_balancing_B.INPUT_6_1_2[0] = robot_simple_balancing_B.FSph[4];
    robot_simple_balancing_B.INPUT_6_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_6_1_3' */
    robot_simple_balancing_B.INPUT_6_1_3[0] = robot_simple_balancing_B.FSph[5];
    robot_simple_balancing_B.INPUT_6_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_6_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_12_1_1' */
    robot_simple_balancing_B.INPUT_12_1_1[0] = robot_simple_balancing_B.FSph_f[6];
    robot_simple_balancing_B.INPUT_12_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_12_1_2' */
    robot_simple_balancing_B.INPUT_12_1_2[0] = robot_simple_balancing_B.FSph_f[7];
    robot_simple_balancing_B.INPUT_12_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_12_1_3' */
    robot_simple_balancing_B.INPUT_12_1_3[0] = robot_simple_balancing_B.FSph_f[8];
    robot_simple_balancing_B.INPUT_12_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_12_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_11_1_1' */
    robot_simple_balancing_B.INPUT_11_1_1[0] = robot_simple_balancing_B.FSph_f[9];
    robot_simple_balancing_B.INPUT_11_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_11_1_2' */
    robot_simple_balancing_B.INPUT_11_1_2[0] = robot_simple_balancing_B.FSph_f
      [10];
    robot_simple_balancing_B.INPUT_11_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_11_1_3' */
    robot_simple_balancing_B.INPUT_11_1_3[0] = robot_simple_balancing_B.FSph_f
      [11];
    robot_simple_balancing_B.INPUT_11_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_11_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_9_1_1' */
    robot_simple_balancing_B.INPUT_9_1_1[0] = robot_simple_balancing_B.FSph_f[0];
    robot_simple_balancing_B.INPUT_9_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_9_1_2' */
    robot_simple_balancing_B.INPUT_9_1_2[0] = robot_simple_balancing_B.FSph_f[1];
    robot_simple_balancing_B.INPUT_9_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_9_1_3' */
    robot_simple_balancing_B.INPUT_9_1_3[0] = robot_simple_balancing_B.FSph_f[2];
    robot_simple_balancing_B.INPUT_9_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_9_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_10_1_1' */
    robot_simple_balancing_B.INPUT_10_1_1[0] = robot_simple_balancing_B.FSph_f[3];
    robot_simple_balancing_B.INPUT_10_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_10_1_2' */
    robot_simple_balancing_B.INPUT_10_1_2[0] = robot_simple_balancing_B.FSph_f[4];
    robot_simple_balancing_B.INPUT_10_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_10_1_3' */
    robot_simple_balancing_B.INPUT_10_1_3[0] = robot_simple_balancing_B.FSph_f[5];
    robot_simple_balancing_B.INPUT_10_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_10_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_16_1_1' */
    robot_simple_balancing_B.INPUT_16_1_1[0] = robot_simple_balancing_B.FSph_n[6];
    robot_simple_balancing_B.INPUT_16_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_16_1_2' */
    robot_simple_balancing_B.INPUT_16_1_2[0] = robot_simple_balancing_B.FSph_n[7];
    robot_simple_balancing_B.INPUT_16_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_16_1_3' */
    robot_simple_balancing_B.INPUT_16_1_3[0] = robot_simple_balancing_B.FSph_n[8];
    robot_simple_balancing_B.INPUT_16_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_16_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_15_1_1' */
    robot_simple_balancing_B.INPUT_15_1_1[0] = robot_simple_balancing_B.FSph_n[9];
    robot_simple_balancing_B.INPUT_15_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_15_1_2' */
    robot_simple_balancing_B.INPUT_15_1_2[0] = robot_simple_balancing_B.FSph_n
      [10];
    robot_simple_balancing_B.INPUT_15_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_15_1_3' */
    robot_simple_balancing_B.INPUT_15_1_3[0] = robot_simple_balancing_B.FSph_n
      [11];
    robot_simple_balancing_B.INPUT_15_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_15_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_13_1_1' */
    robot_simple_balancing_B.INPUT_13_1_1[0] = robot_simple_balancing_B.FSph_n[0];
    robot_simple_balancing_B.INPUT_13_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_13_1_2' */
    robot_simple_balancing_B.INPUT_13_1_2[0] = robot_simple_balancing_B.FSph_n[1];
    robot_simple_balancing_B.INPUT_13_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_13_1_3' */
    robot_simple_balancing_B.INPUT_13_1_3[0] = robot_simple_balancing_B.FSph_n[2];
    robot_simple_balancing_B.INPUT_13_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_13_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_14_1_1' */
    robot_simple_balancing_B.INPUT_14_1_1[0] = robot_simple_balancing_B.FSph_n[3];
    robot_simple_balancing_B.INPUT_14_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_14_1_2' */
    robot_simple_balancing_B.INPUT_14_1_2[0] = robot_simple_balancing_B.FSph_n[4];
    robot_simple_balancing_B.INPUT_14_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_14_1_3' */
    robot_simple_balancing_B.INPUT_14_1_3[0] = robot_simple_balancing_B.FSph_n[5];
    robot_simple_balancing_B.INPUT_14_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_14_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_20_1_1' */
    robot_simple_balancing_B.INPUT_20_1_1[0] = robot_simple_balancing_B.FSph_fe
      [6];
    robot_simple_balancing_B.INPUT_20_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_20_1_2' */
    robot_simple_balancing_B.INPUT_20_1_2[0] = robot_simple_balancing_B.FSph_fe
      [7];
    robot_simple_balancing_B.INPUT_20_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_20_1_3' */
    robot_simple_balancing_B.INPUT_20_1_3[0] = robot_simple_balancing_B.FSph_fe
      [8];
    robot_simple_balancing_B.INPUT_20_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_20_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_19_1_1' */
    robot_simple_balancing_B.INPUT_19_1_1[0] = robot_simple_balancing_B.FSph_fe
      [9];
    robot_simple_balancing_B.INPUT_19_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_19_1_2' */
    robot_simple_balancing_B.INPUT_19_1_2[0] = robot_simple_balancing_B.FSph_fe
      [10];
    robot_simple_balancing_B.INPUT_19_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_19_1_3' */
    robot_simple_balancing_B.INPUT_19_1_3[0] = robot_simple_balancing_B.FSph_fe
      [11];
    robot_simple_balancing_B.INPUT_19_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_19_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_17_1_1' */
    robot_simple_balancing_B.INPUT_17_1_1[0] = robot_simple_balancing_B.FSph_fe
      [0];
    robot_simple_balancing_B.INPUT_17_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_17_1_2' */
    robot_simple_balancing_B.INPUT_17_1_2[0] = robot_simple_balancing_B.FSph_fe
      [1];
    robot_simple_balancing_B.INPUT_17_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_17_1_3' */
    robot_simple_balancing_B.INPUT_17_1_3[0] = robot_simple_balancing_B.FSph_fe
      [2];
    robot_simple_balancing_B.INPUT_17_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_17_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_18_1_1' */
    robot_simple_balancing_B.INPUT_18_1_1[0] = robot_simple_balancing_B.FSph_fe
      [3];
    robot_simple_balancing_B.INPUT_18_1_1[1] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_1[2] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_18_1_2' */
    robot_simple_balancing_B.INPUT_18_1_2[0] = robot_simple_balancing_B.FSph_fe
      [4];
    robot_simple_balancing_B.INPUT_18_1_2[1] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_2[2] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S29>/INPUT_18_1_3' */
    robot_simple_balancing_B.INPUT_18_1_3[0] = robot_simple_balancing_B.FSph_fe
      [5];
    robot_simple_balancing_B.INPUT_18_1_3[1] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_3[2] = 0.0;
    robot_simple_balancing_B.INPUT_18_1_3[3] = 0.0;
  }

  if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(robot_simple_balancing_M->rtwLogInfo,
                        (robot_simple_balancing_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[272];
    int_T tmp_1[69];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;
    if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
      /* Update for Delay: '<Root>/Delay' */
      memcpy(&robot_simple_balancing_DW.Delay_DSTATE[0],
             &robot_simple_balancing_B.OUTPUT_1_0[68], 9U * sizeof(real_T));
    }

    /* Update for SimscapeExecutionBlock: '<S29>/STATE_1' */
    simulationData = (NeslSimulationData *)
      robot_simple_balancing_DW.STATE_1_SimData;
    time = robot_simple_balancing_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX =
      &robot_simple_balancing_X.robot_simple_balancingx6_DOF_Jo[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &robot_simple_balancing_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &robot_simple_balancing_DW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (robot_simple_balancing_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&robot_simple_balancing_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = robot_simple_balancing_B.INPUT_1_1_1[0];
    tmp_0[1] = robot_simple_balancing_B.INPUT_1_1_1[1];
    tmp_0[2] = robot_simple_balancing_B.INPUT_1_1_1[2];
    tmp_0[3] = robot_simple_balancing_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = robot_simple_balancing_B.INPUT_2_1_1[0];
    tmp_0[5] = robot_simple_balancing_B.INPUT_2_1_1[1];
    tmp_0[6] = robot_simple_balancing_B.INPUT_2_1_1[2];
    tmp_0[7] = robot_simple_balancing_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = robot_simple_balancing_B.INPUT_3_1_1[0];
    tmp_0[9] = robot_simple_balancing_B.INPUT_3_1_1[1];
    tmp_0[10] = robot_simple_balancing_B.INPUT_3_1_1[2];
    tmp_0[11] = robot_simple_balancing_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = robot_simple_balancing_B.INPUT_4_1_1[0];
    tmp_0[13] = robot_simple_balancing_B.INPUT_4_1_1[1];
    tmp_0[14] = robot_simple_balancing_B.INPUT_4_1_1[2];
    tmp_0[15] = robot_simple_balancing_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = robot_simple_balancing_B.INPUT_23_1_1[0];
    tmp_0[17] = robot_simple_balancing_B.INPUT_23_1_1[1];
    tmp_0[18] = robot_simple_balancing_B.INPUT_23_1_1[2];
    tmp_0[19] = robot_simple_balancing_B.INPUT_23_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = robot_simple_balancing_B.INPUT_21_1_1[0];
    tmp_0[21] = robot_simple_balancing_B.INPUT_21_1_1[1];
    tmp_0[22] = robot_simple_balancing_B.INPUT_21_1_1[2];
    tmp_0[23] = robot_simple_balancing_B.INPUT_21_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = robot_simple_balancing_B.INPUT_22_1_1[0];
    tmp_0[25] = robot_simple_balancing_B.INPUT_22_1_1[1];
    tmp_0[26] = robot_simple_balancing_B.INPUT_22_1_1[2];
    tmp_0[27] = robot_simple_balancing_B.INPUT_22_1_1[3];
    tmp_1[7] = 28;
    tmp_0[28] = robot_simple_balancing_B.INPUT_24_1_1[0];
    tmp_0[29] = robot_simple_balancing_B.INPUT_24_1_1[1];
    tmp_0[30] = robot_simple_balancing_B.INPUT_24_1_1[2];
    tmp_0[31] = robot_simple_balancing_B.INPUT_24_1_1[3];
    tmp_1[8] = 32;
    tmp_0[32] = robot_simple_balancing_B.INPUT_27_1_1[0];
    tmp_0[33] = robot_simple_balancing_B.INPUT_27_1_1[1];
    tmp_0[34] = robot_simple_balancing_B.INPUT_27_1_1[2];
    tmp_0[35] = robot_simple_balancing_B.INPUT_27_1_1[3];
    tmp_1[9] = 36;
    tmp_0[36] = robot_simple_balancing_B.INPUT_25_1_1[0];
    tmp_0[37] = robot_simple_balancing_B.INPUT_25_1_1[1];
    tmp_0[38] = robot_simple_balancing_B.INPUT_25_1_1[2];
    tmp_0[39] = robot_simple_balancing_B.INPUT_25_1_1[3];
    tmp_1[10] = 40;
    tmp_0[40] = robot_simple_balancing_B.INPUT_26_1_1[0];
    tmp_0[41] = robot_simple_balancing_B.INPUT_26_1_1[1];
    tmp_0[42] = robot_simple_balancing_B.INPUT_26_1_1[2];
    tmp_0[43] = robot_simple_balancing_B.INPUT_26_1_1[3];
    tmp_1[11] = 44;
    tmp_0[44] = robot_simple_balancing_B.INPUT_28_1_1[0];
    tmp_0[45] = robot_simple_balancing_B.INPUT_28_1_1[1];
    tmp_0[46] = robot_simple_balancing_B.INPUT_28_1_1[2];
    tmp_0[47] = robot_simple_balancing_B.INPUT_28_1_1[3];
    tmp_1[12] = 48;
    tmp_0[48] = robot_simple_balancing_B.INPUT_31_1_1[0];
    tmp_0[49] = robot_simple_balancing_B.INPUT_31_1_1[1];
    tmp_0[50] = robot_simple_balancing_B.INPUT_31_1_1[2];
    tmp_0[51] = robot_simple_balancing_B.INPUT_31_1_1[3];
    tmp_1[13] = 52;
    tmp_0[52] = robot_simple_balancing_B.INPUT_29_1_1[0];
    tmp_0[53] = robot_simple_balancing_B.INPUT_29_1_1[1];
    tmp_0[54] = robot_simple_balancing_B.INPUT_29_1_1[2];
    tmp_0[55] = robot_simple_balancing_B.INPUT_29_1_1[3];
    tmp_1[14] = 56;
    tmp_0[56] = robot_simple_balancing_B.INPUT_30_1_1[0];
    tmp_0[57] = robot_simple_balancing_B.INPUT_30_1_1[1];
    tmp_0[58] = robot_simple_balancing_B.INPUT_30_1_1[2];
    tmp_0[59] = robot_simple_balancing_B.INPUT_30_1_1[3];
    tmp_1[15] = 60;
    tmp_0[60] = robot_simple_balancing_B.INPUT_32_1_1[0];
    tmp_0[61] = robot_simple_balancing_B.INPUT_32_1_1[1];
    tmp_0[62] = robot_simple_balancing_B.INPUT_32_1_1[2];
    tmp_0[63] = robot_simple_balancing_B.INPUT_32_1_1[3];
    tmp_1[16] = 64;
    tmp_0[64] = robot_simple_balancing_B.INPUT_35_1_1[0];
    tmp_0[65] = robot_simple_balancing_B.INPUT_35_1_1[1];
    tmp_0[66] = robot_simple_balancing_B.INPUT_35_1_1[2];
    tmp_0[67] = robot_simple_balancing_B.INPUT_35_1_1[3];
    tmp_1[17] = 68;
    tmp_0[68] = robot_simple_balancing_B.INPUT_33_1_1[0];
    tmp_0[69] = robot_simple_balancing_B.INPUT_33_1_1[1];
    tmp_0[70] = robot_simple_balancing_B.INPUT_33_1_1[2];
    tmp_0[71] = robot_simple_balancing_B.INPUT_33_1_1[3];
    tmp_1[18] = 72;
    tmp_0[72] = robot_simple_balancing_B.INPUT_34_1_1[0];
    tmp_0[73] = robot_simple_balancing_B.INPUT_34_1_1[1];
    tmp_0[74] = robot_simple_balancing_B.INPUT_34_1_1[2];
    tmp_0[75] = robot_simple_balancing_B.INPUT_34_1_1[3];
    tmp_1[19] = 76;
    tmp_0[76] = robot_simple_balancing_B.INPUT_36_1_1[0];
    tmp_0[77] = robot_simple_balancing_B.INPUT_36_1_1[1];
    tmp_0[78] = robot_simple_balancing_B.INPUT_36_1_1[2];
    tmp_0[79] = robot_simple_balancing_B.INPUT_36_1_1[3];
    tmp_1[20] = 80;
    tmp_0[80] = robot_simple_balancing_B.INPUT_8_1_1[0];
    tmp_0[81] = robot_simple_balancing_B.INPUT_8_1_1[1];
    tmp_0[82] = robot_simple_balancing_B.INPUT_8_1_1[2];
    tmp_0[83] = robot_simple_balancing_B.INPUT_8_1_1[3];
    tmp_1[21] = 84;
    tmp_0[84] = robot_simple_balancing_B.INPUT_8_1_2[0];
    tmp_0[85] = robot_simple_balancing_B.INPUT_8_1_2[1];
    tmp_0[86] = robot_simple_balancing_B.INPUT_8_1_2[2];
    tmp_0[87] = robot_simple_balancing_B.INPUT_8_1_2[3];
    tmp_1[22] = 88;
    tmp_0[88] = robot_simple_balancing_B.INPUT_8_1_3[0];
    tmp_0[89] = robot_simple_balancing_B.INPUT_8_1_3[1];
    tmp_0[90] = robot_simple_balancing_B.INPUT_8_1_3[2];
    tmp_0[91] = robot_simple_balancing_B.INPUT_8_1_3[3];
    tmp_1[23] = 92;
    tmp_0[92] = robot_simple_balancing_B.INPUT_7_1_1[0];
    tmp_0[93] = robot_simple_balancing_B.INPUT_7_1_1[1];
    tmp_0[94] = robot_simple_balancing_B.INPUT_7_1_1[2];
    tmp_0[95] = robot_simple_balancing_B.INPUT_7_1_1[3];
    tmp_1[24] = 96;
    tmp_0[96] = robot_simple_balancing_B.INPUT_7_1_2[0];
    tmp_0[97] = robot_simple_balancing_B.INPUT_7_1_2[1];
    tmp_0[98] = robot_simple_balancing_B.INPUT_7_1_2[2];
    tmp_0[99] = robot_simple_balancing_B.INPUT_7_1_2[3];
    tmp_1[25] = 100;
    tmp_0[100] = robot_simple_balancing_B.INPUT_7_1_3[0];
    tmp_0[101] = robot_simple_balancing_B.INPUT_7_1_3[1];
    tmp_0[102] = robot_simple_balancing_B.INPUT_7_1_3[2];
    tmp_0[103] = robot_simple_balancing_B.INPUT_7_1_3[3];
    tmp_1[26] = 104;
    tmp_0[104] = robot_simple_balancing_B.INPUT_5_1_1[0];
    tmp_0[105] = robot_simple_balancing_B.INPUT_5_1_1[1];
    tmp_0[106] = robot_simple_balancing_B.INPUT_5_1_1[2];
    tmp_0[107] = robot_simple_balancing_B.INPUT_5_1_1[3];
    tmp_1[27] = 108;
    tmp_0[108] = robot_simple_balancing_B.INPUT_5_1_2[0];
    tmp_0[109] = robot_simple_balancing_B.INPUT_5_1_2[1];
    tmp_0[110] = robot_simple_balancing_B.INPUT_5_1_2[2];
    tmp_0[111] = robot_simple_balancing_B.INPUT_5_1_2[3];
    tmp_1[28] = 112;
    tmp_0[112] = robot_simple_balancing_B.INPUT_5_1_3[0];
    tmp_0[113] = robot_simple_balancing_B.INPUT_5_1_3[1];
    tmp_0[114] = robot_simple_balancing_B.INPUT_5_1_3[2];
    tmp_0[115] = robot_simple_balancing_B.INPUT_5_1_3[3];
    tmp_1[29] = 116;
    tmp_0[116] = robot_simple_balancing_B.INPUT_6_1_1[0];
    tmp_0[117] = robot_simple_balancing_B.INPUT_6_1_1[1];
    tmp_0[118] = robot_simple_balancing_B.INPUT_6_1_1[2];
    tmp_0[119] = robot_simple_balancing_B.INPUT_6_1_1[3];
    tmp_1[30] = 120;
    tmp_0[120] = robot_simple_balancing_B.INPUT_6_1_2[0];
    tmp_0[121] = robot_simple_balancing_B.INPUT_6_1_2[1];
    tmp_0[122] = robot_simple_balancing_B.INPUT_6_1_2[2];
    tmp_0[123] = robot_simple_balancing_B.INPUT_6_1_2[3];
    tmp_1[31] = 124;
    tmp_0[124] = robot_simple_balancing_B.INPUT_6_1_3[0];
    tmp_0[125] = robot_simple_balancing_B.INPUT_6_1_3[1];
    tmp_0[126] = robot_simple_balancing_B.INPUT_6_1_3[2];
    tmp_0[127] = robot_simple_balancing_B.INPUT_6_1_3[3];
    tmp_1[32] = 128;
    tmp_0[128] = robot_simple_balancing_B.INPUT_12_1_1[0];
    tmp_0[129] = robot_simple_balancing_B.INPUT_12_1_1[1];
    tmp_0[130] = robot_simple_balancing_B.INPUT_12_1_1[2];
    tmp_0[131] = robot_simple_balancing_B.INPUT_12_1_1[3];
    tmp_1[33] = 132;
    tmp_0[132] = robot_simple_balancing_B.INPUT_12_1_2[0];
    tmp_0[133] = robot_simple_balancing_B.INPUT_12_1_2[1];
    tmp_0[134] = robot_simple_balancing_B.INPUT_12_1_2[2];
    tmp_0[135] = robot_simple_balancing_B.INPUT_12_1_2[3];
    tmp_1[34] = 136;
    tmp_0[136] = robot_simple_balancing_B.INPUT_12_1_3[0];
    tmp_0[137] = robot_simple_balancing_B.INPUT_12_1_3[1];
    tmp_0[138] = robot_simple_balancing_B.INPUT_12_1_3[2];
    tmp_0[139] = robot_simple_balancing_B.INPUT_12_1_3[3];
    tmp_1[35] = 140;
    tmp_0[140] = robot_simple_balancing_B.INPUT_11_1_1[0];
    tmp_0[141] = robot_simple_balancing_B.INPUT_11_1_1[1];
    tmp_0[142] = robot_simple_balancing_B.INPUT_11_1_1[2];
    tmp_0[143] = robot_simple_balancing_B.INPUT_11_1_1[3];
    tmp_1[36] = 144;
    tmp_0[144] = robot_simple_balancing_B.INPUT_11_1_2[0];
    tmp_0[145] = robot_simple_balancing_B.INPUT_11_1_2[1];
    tmp_0[146] = robot_simple_balancing_B.INPUT_11_1_2[2];
    tmp_0[147] = robot_simple_balancing_B.INPUT_11_1_2[3];
    tmp_1[37] = 148;
    tmp_0[148] = robot_simple_balancing_B.INPUT_11_1_3[0];
    tmp_0[149] = robot_simple_balancing_B.INPUT_11_1_3[1];
    tmp_0[150] = robot_simple_balancing_B.INPUT_11_1_3[2];
    tmp_0[151] = robot_simple_balancing_B.INPUT_11_1_3[3];
    tmp_1[38] = 152;
    tmp_0[152] = robot_simple_balancing_B.INPUT_9_1_1[0];
    tmp_0[153] = robot_simple_balancing_B.INPUT_9_1_1[1];
    tmp_0[154] = robot_simple_balancing_B.INPUT_9_1_1[2];
    tmp_0[155] = robot_simple_balancing_B.INPUT_9_1_1[3];
    tmp_1[39] = 156;
    tmp_0[156] = robot_simple_balancing_B.INPUT_9_1_2[0];
    tmp_0[157] = robot_simple_balancing_B.INPUT_9_1_2[1];
    tmp_0[158] = robot_simple_balancing_B.INPUT_9_1_2[2];
    tmp_0[159] = robot_simple_balancing_B.INPUT_9_1_2[3];
    tmp_1[40] = 160;
    tmp_0[160] = robot_simple_balancing_B.INPUT_9_1_3[0];
    tmp_0[161] = robot_simple_balancing_B.INPUT_9_1_3[1];
    tmp_0[162] = robot_simple_balancing_B.INPUT_9_1_3[2];
    tmp_0[163] = robot_simple_balancing_B.INPUT_9_1_3[3];
    tmp_1[41] = 164;
    tmp_0[164] = robot_simple_balancing_B.INPUT_10_1_1[0];
    tmp_0[165] = robot_simple_balancing_B.INPUT_10_1_1[1];
    tmp_0[166] = robot_simple_balancing_B.INPUT_10_1_1[2];
    tmp_0[167] = robot_simple_balancing_B.INPUT_10_1_1[3];
    tmp_1[42] = 168;
    tmp_0[168] = robot_simple_balancing_B.INPUT_10_1_2[0];
    tmp_0[169] = robot_simple_balancing_B.INPUT_10_1_2[1];
    tmp_0[170] = robot_simple_balancing_B.INPUT_10_1_2[2];
    tmp_0[171] = robot_simple_balancing_B.INPUT_10_1_2[3];
    tmp_1[43] = 172;
    tmp_0[172] = robot_simple_balancing_B.INPUT_10_1_3[0];
    tmp_0[173] = robot_simple_balancing_B.INPUT_10_1_3[1];
    tmp_0[174] = robot_simple_balancing_B.INPUT_10_1_3[2];
    tmp_0[175] = robot_simple_balancing_B.INPUT_10_1_3[3];
    tmp_1[44] = 176;
    tmp_0[176] = robot_simple_balancing_B.INPUT_16_1_1[0];
    tmp_0[177] = robot_simple_balancing_B.INPUT_16_1_1[1];
    tmp_0[178] = robot_simple_balancing_B.INPUT_16_1_1[2];
    tmp_0[179] = robot_simple_balancing_B.INPUT_16_1_1[3];
    tmp_1[45] = 180;
    tmp_0[180] = robot_simple_balancing_B.INPUT_16_1_2[0];
    tmp_0[181] = robot_simple_balancing_B.INPUT_16_1_2[1];
    tmp_0[182] = robot_simple_balancing_B.INPUT_16_1_2[2];
    tmp_0[183] = robot_simple_balancing_B.INPUT_16_1_2[3];
    tmp_1[46] = 184;
    tmp_0[184] = robot_simple_balancing_B.INPUT_16_1_3[0];
    tmp_0[185] = robot_simple_balancing_B.INPUT_16_1_3[1];
    tmp_0[186] = robot_simple_balancing_B.INPUT_16_1_3[2];
    tmp_0[187] = robot_simple_balancing_B.INPUT_16_1_3[3];
    tmp_1[47] = 188;
    tmp_0[188] = robot_simple_balancing_B.INPUT_15_1_1[0];
    tmp_0[189] = robot_simple_balancing_B.INPUT_15_1_1[1];
    tmp_0[190] = robot_simple_balancing_B.INPUT_15_1_1[2];
    tmp_0[191] = robot_simple_balancing_B.INPUT_15_1_1[3];
    tmp_1[48] = 192;
    tmp_0[192] = robot_simple_balancing_B.INPUT_15_1_2[0];
    tmp_0[193] = robot_simple_balancing_B.INPUT_15_1_2[1];
    tmp_0[194] = robot_simple_balancing_B.INPUT_15_1_2[2];
    tmp_0[195] = robot_simple_balancing_B.INPUT_15_1_2[3];
    tmp_1[49] = 196;
    tmp_0[196] = robot_simple_balancing_B.INPUT_15_1_3[0];
    tmp_0[197] = robot_simple_balancing_B.INPUT_15_1_3[1];
    tmp_0[198] = robot_simple_balancing_B.INPUT_15_1_3[2];
    tmp_0[199] = robot_simple_balancing_B.INPUT_15_1_3[3];
    tmp_1[50] = 200;
    tmp_0[200] = robot_simple_balancing_B.INPUT_13_1_1[0];
    tmp_0[201] = robot_simple_balancing_B.INPUT_13_1_1[1];
    tmp_0[202] = robot_simple_balancing_B.INPUT_13_1_1[2];
    tmp_0[203] = robot_simple_balancing_B.INPUT_13_1_1[3];
    tmp_1[51] = 204;
    tmp_0[204] = robot_simple_balancing_B.INPUT_13_1_2[0];
    tmp_0[205] = robot_simple_balancing_B.INPUT_13_1_2[1];
    tmp_0[206] = robot_simple_balancing_B.INPUT_13_1_2[2];
    tmp_0[207] = robot_simple_balancing_B.INPUT_13_1_2[3];
    tmp_1[52] = 208;
    tmp_0[208] = robot_simple_balancing_B.INPUT_13_1_3[0];
    tmp_0[209] = robot_simple_balancing_B.INPUT_13_1_3[1];
    tmp_0[210] = robot_simple_balancing_B.INPUT_13_1_3[2];
    tmp_0[211] = robot_simple_balancing_B.INPUT_13_1_3[3];
    tmp_1[53] = 212;
    tmp_0[212] = robot_simple_balancing_B.INPUT_14_1_1[0];
    tmp_0[213] = robot_simple_balancing_B.INPUT_14_1_1[1];
    tmp_0[214] = robot_simple_balancing_B.INPUT_14_1_1[2];
    tmp_0[215] = robot_simple_balancing_B.INPUT_14_1_1[3];
    tmp_1[54] = 216;
    tmp_0[216] = robot_simple_balancing_B.INPUT_14_1_2[0];
    tmp_0[217] = robot_simple_balancing_B.INPUT_14_1_2[1];
    tmp_0[218] = robot_simple_balancing_B.INPUT_14_1_2[2];
    tmp_0[219] = robot_simple_balancing_B.INPUT_14_1_2[3];
    tmp_1[55] = 220;
    tmp_0[220] = robot_simple_balancing_B.INPUT_14_1_3[0];
    tmp_0[221] = robot_simple_balancing_B.INPUT_14_1_3[1];
    tmp_0[222] = robot_simple_balancing_B.INPUT_14_1_3[2];
    tmp_0[223] = robot_simple_balancing_B.INPUT_14_1_3[3];
    tmp_1[56] = 224;
    tmp_0[224] = robot_simple_balancing_B.INPUT_20_1_1[0];
    tmp_0[225] = robot_simple_balancing_B.INPUT_20_1_1[1];
    tmp_0[226] = robot_simple_balancing_B.INPUT_20_1_1[2];
    tmp_0[227] = robot_simple_balancing_B.INPUT_20_1_1[3];
    tmp_1[57] = 228;
    tmp_0[228] = robot_simple_balancing_B.INPUT_20_1_2[0];
    tmp_0[229] = robot_simple_balancing_B.INPUT_20_1_2[1];
    tmp_0[230] = robot_simple_balancing_B.INPUT_20_1_2[2];
    tmp_0[231] = robot_simple_balancing_B.INPUT_20_1_2[3];
    tmp_1[58] = 232;
    tmp_0[232] = robot_simple_balancing_B.INPUT_20_1_3[0];
    tmp_0[233] = robot_simple_balancing_B.INPUT_20_1_3[1];
    tmp_0[234] = robot_simple_balancing_B.INPUT_20_1_3[2];
    tmp_0[235] = robot_simple_balancing_B.INPUT_20_1_3[3];
    tmp_1[59] = 236;
    tmp_0[236] = robot_simple_balancing_B.INPUT_19_1_1[0];
    tmp_0[237] = robot_simple_balancing_B.INPUT_19_1_1[1];
    tmp_0[238] = robot_simple_balancing_B.INPUT_19_1_1[2];
    tmp_0[239] = robot_simple_balancing_B.INPUT_19_1_1[3];
    tmp_1[60] = 240;
    tmp_0[240] = robot_simple_balancing_B.INPUT_19_1_2[0];
    tmp_0[241] = robot_simple_balancing_B.INPUT_19_1_2[1];
    tmp_0[242] = robot_simple_balancing_B.INPUT_19_1_2[2];
    tmp_0[243] = robot_simple_balancing_B.INPUT_19_1_2[3];
    tmp_1[61] = 244;
    tmp_0[244] = robot_simple_balancing_B.INPUT_19_1_3[0];
    tmp_0[245] = robot_simple_balancing_B.INPUT_19_1_3[1];
    tmp_0[246] = robot_simple_balancing_B.INPUT_19_1_3[2];
    tmp_0[247] = robot_simple_balancing_B.INPUT_19_1_3[3];
    tmp_1[62] = 248;
    tmp_0[248] = robot_simple_balancing_B.INPUT_17_1_1[0];
    tmp_0[249] = robot_simple_balancing_B.INPUT_17_1_1[1];
    tmp_0[250] = robot_simple_balancing_B.INPUT_17_1_1[2];
    tmp_0[251] = robot_simple_balancing_B.INPUT_17_1_1[3];
    tmp_1[63] = 252;
    tmp_0[252] = robot_simple_balancing_B.INPUT_17_1_2[0];
    tmp_0[253] = robot_simple_balancing_B.INPUT_17_1_2[1];
    tmp_0[254] = robot_simple_balancing_B.INPUT_17_1_2[2];
    tmp_0[255] = robot_simple_balancing_B.INPUT_17_1_2[3];
    tmp_1[64] = 256;
    tmp_0[256] = robot_simple_balancing_B.INPUT_17_1_3[0];
    tmp_0[257] = robot_simple_balancing_B.INPUT_17_1_3[1];
    tmp_0[258] = robot_simple_balancing_B.INPUT_17_1_3[2];
    tmp_0[259] = robot_simple_balancing_B.INPUT_17_1_3[3];
    tmp_1[65] = 260;
    tmp_0[260] = robot_simple_balancing_B.INPUT_18_1_1[0];
    tmp_0[261] = robot_simple_balancing_B.INPUT_18_1_1[1];
    tmp_0[262] = robot_simple_balancing_B.INPUT_18_1_1[2];
    tmp_0[263] = robot_simple_balancing_B.INPUT_18_1_1[3];
    tmp_1[66] = 264;
    tmp_0[264] = robot_simple_balancing_B.INPUT_18_1_2[0];
    tmp_0[265] = robot_simple_balancing_B.INPUT_18_1_2[1];
    tmp_0[266] = robot_simple_balancing_B.INPUT_18_1_2[2];
    tmp_0[267] = robot_simple_balancing_B.INPUT_18_1_2[3];
    tmp_1[67] = 268;
    tmp_0[268] = robot_simple_balancing_B.INPUT_18_1_3[0];
    tmp_0[269] = robot_simple_balancing_B.INPUT_18_1_3[1];
    tmp_0[270] = robot_simple_balancing_B.INPUT_18_1_3[2];
    tmp_0[271] = robot_simple_balancing_B.INPUT_18_1_3[3];
    tmp_1[68] = 272;
    simulationData->mData->mInputValues.mN = 272;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 69;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      robot_simple_balancing_DW.STATE_1_Simulator, NESL_SIM_UPDATE,
      simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S29>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(robot_simple_balancing_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(robot_simple_balancing_M)!=-1) &&
          !((rtmGetTFinal(robot_simple_balancing_M)-
             (((robot_simple_balancing_M->Timing.clockTick1+
                robot_simple_balancing_M->Timing.clockTickH1* 4294967296.0)) *
              0.001)) > (((robot_simple_balancing_M->Timing.clockTick1+
                           robot_simple_balancing_M->Timing.clockTickH1*
                           4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(robot_simple_balancing_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&robot_simple_balancing_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++robot_simple_balancing_M->Timing.clockTick0)) {
      ++robot_simple_balancing_M->Timing.clockTickH0;
    }

    robot_simple_balancing_M->Timing.t[0] = rtsiGetSolverStopTime
      (&robot_simple_balancing_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      robot_simple_balancing_M->Timing.clockTick1++;
      if (!robot_simple_balancing_M->Timing.clockTick1) {
        robot_simple_balancing_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void robot_simple_balancing_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[272];
  int_T tmp_1[69];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_2;
  char *msg;
  XDot_robot_simple_balancing_T *_rtXdot;
  _rtXdot = ((XDot_robot_simple_balancing_T *) robot_simple_balancing_M->derivs);

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_1_1_1' */
  _rtXdot->robot_simple_balancingSPConv6ou[0] =
    robot_simple_balancing_X.robot_simple_balancingSPConv6ou[1];
  _rtXdot->robot_simple_balancingSPConv6ou[1] = ((robot_simple_balancing_B.x -
    robot_simple_balancing_X.robot_simple_balancingSPConv6ou[0]) * 1000.0 - 2.0 *
    robot_simple_balancing_X.robot_simple_balancingSPConv6ou[1]) * 1000.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_2_1_1' */
  _rtXdot->robot_simple_balancingSPConv7ou[0] =
    robot_simple_balancing_X.robot_simple_balancingSPConv7ou[1];
  _rtXdot->robot_simple_balancingSPConv7ou[1] = ((robot_simple_balancing_B.y -
    robot_simple_balancing_X.robot_simple_balancingSPConv7ou[0]) * 1000.0 - 2.0 *
    robot_simple_balancing_X.robot_simple_balancingSPConv7ou[1]) * 1000.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_3_1_1' */
  _rtXdot->robot_simple_balancingSPConv8ou[0] =
    robot_simple_balancing_X.robot_simple_balancingSPConv8ou[1];
  _rtXdot->robot_simple_balancingSPConv8ou[1] = ((robot_simple_balancing_B.z -
    robot_simple_balancing_X.robot_simple_balancingSPConv8ou[0]) * 1000.0 - 2.0 *
    robot_simple_balancing_X.robot_simple_balancingSPConv8ou[1]) * 1000.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_4_1_1' */
  _rtXdot->robot_simple_balancingSimulink_[0] =
    robot_simple_balancing_X.robot_simple_balancingSimulink_[1];
  _rtXdot->robot_simple_balancingSimulink_[1] =
    ((robot_simple_balancing_B.Switch -
      robot_simple_balancing_X.robot_simple_balancingSimulink_[0]) * 100.0 - 2.0
     * robot_simple_balancing_X.robot_simple_balancingSimulink_[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_23_1_1' */
  _rtXdot->robot_simple_balancingSubsystem[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsystem[1];
  _rtXdot->robot_simple_balancingSubsystem[1] = ((robot_simple_balancing_B.Sum[0]
    - robot_simple_balancing_X.robot_simple_balancingSubsystem[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsystem[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_21_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_m[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_m[1];
  _rtXdot->robot_simple_balancingSubsyst_m[1] = ((robot_simple_balancing_B.Sum[1]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_m[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_m[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_22_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_o[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_o[1];
  _rtXdot->robot_simple_balancingSubsyst_o[1] = ((robot_simple_balancing_B.Sum[2]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_o[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_o[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_24_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_i[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_i[1];
  _rtXdot->robot_simple_balancingSubsyst_i[1] = ((robot_simple_balancing_B.Sum[3]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_i[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_i[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_27_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_d[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_d[1];
  _rtXdot->robot_simple_balancingSubsyst_d[1] = ((robot_simple_balancing_B.Sum[4]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_d[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_d[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_25_1_1' */
  _rtXdot->robot_simple_balancingSubsys_ie[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsys_ie[1];
  _rtXdot->robot_simple_balancingSubsys_ie[1] = ((robot_simple_balancing_B.Sum[5]
    - robot_simple_balancing_X.robot_simple_balancingSubsys_ie[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsys_ie[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_26_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_e[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_e[1];
  _rtXdot->robot_simple_balancingSubsyst_e[1] = ((robot_simple_balancing_B.Sum[6]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_e[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_e[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_28_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_f[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_f[1];
  _rtXdot->robot_simple_balancingSubsyst_f[1] = ((robot_simple_balancing_B.Sum[7]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_f[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_f[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_31_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_j[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_j[1];
  _rtXdot->robot_simple_balancingSubsyst_j[1] = ((robot_simple_balancing_B.Sum[8]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_j[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_j[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_29_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_k[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_k[1];
  _rtXdot->robot_simple_balancingSubsyst_k[1] = ((robot_simple_balancing_B.Sum[9]
    - robot_simple_balancing_X.robot_simple_balancingSubsyst_k[0]) * 100.0 - 2.0
    * robot_simple_balancing_X.robot_simple_balancingSubsyst_k[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_30_1_1' */
  _rtXdot->robot_simple_balancingSubsys_jm[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsys_jm[1];
  _rtXdot->robot_simple_balancingSubsys_jm[1] = ((robot_simple_balancing_B.Sum
    [10] - robot_simple_balancing_X.robot_simple_balancingSubsys_jm[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_jm[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_32_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_a[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_a[1];
  _rtXdot->robot_simple_balancingSubsyst_a[1] = ((robot_simple_balancing_B.Sum
    [11] - robot_simple_balancing_X.robot_simple_balancingSubsyst_a[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_a[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_35_1_1' */
  _rtXdot->robot_simple_balancingSubsys_ma[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsys_ma[1];
  _rtXdot->robot_simple_balancingSubsys_ma[1] = ((robot_simple_balancing_B.Sum
    [12] - robot_simple_balancing_X.robot_simple_balancingSubsys_ma[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_ma[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_33_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_l[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_l[1];
  _rtXdot->robot_simple_balancingSubsyst_l[1] = ((robot_simple_balancing_B.Sum
    [13] - robot_simple_balancing_X.robot_simple_balancingSubsyst_l[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_l[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_34_1_1' */
  _rtXdot->robot_simple_balancingSubsys_mm[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsys_mm[1];
  _rtXdot->robot_simple_balancingSubsys_mm[1] = ((robot_simple_balancing_B.Sum
    [14] - robot_simple_balancing_X.robot_simple_balancingSubsys_mm[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsys_mm[1]) * 100.0;

  /* Derivatives for SimscapeInputBlock: '<S29>/INPUT_36_1_1' */
  _rtXdot->robot_simple_balancingSubsyst_p[0] =
    robot_simple_balancing_X.robot_simple_balancingSubsyst_p[1];
  _rtXdot->robot_simple_balancingSubsyst_p[1] = ((robot_simple_balancing_B.Sum
    [15] - robot_simple_balancing_X.robot_simple_balancingSubsyst_p[0]) * 100.0
    - 2.0 * robot_simple_balancing_X.robot_simple_balancingSubsyst_p[1]) * 100.0;

  /* Derivatives for SimscapeExecutionBlock: '<S29>/STATE_1' */
  simulationData = (NeslSimulationData *)
    robot_simple_balancing_DW.STATE_1_SimData;
  time = robot_simple_balancing_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 13;
  simulationData->mData->mContStates.mX =
    &robot_simple_balancing_X.robot_simple_balancingx6_DOF_Jo[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &robot_simple_balancing_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX =
    &robot_simple_balancing_DW.STATE_1_Modes;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (robot_simple_balancing_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&robot_simple_balancing_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = robot_simple_balancing_B.INPUT_1_1_1[0];
  tmp_0[1] = robot_simple_balancing_B.INPUT_1_1_1[1];
  tmp_0[2] = robot_simple_balancing_B.INPUT_1_1_1[2];
  tmp_0[3] = robot_simple_balancing_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = robot_simple_balancing_B.INPUT_2_1_1[0];
  tmp_0[5] = robot_simple_balancing_B.INPUT_2_1_1[1];
  tmp_0[6] = robot_simple_balancing_B.INPUT_2_1_1[2];
  tmp_0[7] = robot_simple_balancing_B.INPUT_2_1_1[3];
  tmp_1[2] = 8;
  tmp_0[8] = robot_simple_balancing_B.INPUT_3_1_1[0];
  tmp_0[9] = robot_simple_balancing_B.INPUT_3_1_1[1];
  tmp_0[10] = robot_simple_balancing_B.INPUT_3_1_1[2];
  tmp_0[11] = robot_simple_balancing_B.INPUT_3_1_1[3];
  tmp_1[3] = 12;
  tmp_0[12] = robot_simple_balancing_B.INPUT_4_1_1[0];
  tmp_0[13] = robot_simple_balancing_B.INPUT_4_1_1[1];
  tmp_0[14] = robot_simple_balancing_B.INPUT_4_1_1[2];
  tmp_0[15] = robot_simple_balancing_B.INPUT_4_1_1[3];
  tmp_1[4] = 16;
  tmp_0[16] = robot_simple_balancing_B.INPUT_23_1_1[0];
  tmp_0[17] = robot_simple_balancing_B.INPUT_23_1_1[1];
  tmp_0[18] = robot_simple_balancing_B.INPUT_23_1_1[2];
  tmp_0[19] = robot_simple_balancing_B.INPUT_23_1_1[3];
  tmp_1[5] = 20;
  tmp_0[20] = robot_simple_balancing_B.INPUT_21_1_1[0];
  tmp_0[21] = robot_simple_balancing_B.INPUT_21_1_1[1];
  tmp_0[22] = robot_simple_balancing_B.INPUT_21_1_1[2];
  tmp_0[23] = robot_simple_balancing_B.INPUT_21_1_1[3];
  tmp_1[6] = 24;
  tmp_0[24] = robot_simple_balancing_B.INPUT_22_1_1[0];
  tmp_0[25] = robot_simple_balancing_B.INPUT_22_1_1[1];
  tmp_0[26] = robot_simple_balancing_B.INPUT_22_1_1[2];
  tmp_0[27] = robot_simple_balancing_B.INPUT_22_1_1[3];
  tmp_1[7] = 28;
  tmp_0[28] = robot_simple_balancing_B.INPUT_24_1_1[0];
  tmp_0[29] = robot_simple_balancing_B.INPUT_24_1_1[1];
  tmp_0[30] = robot_simple_balancing_B.INPUT_24_1_1[2];
  tmp_0[31] = robot_simple_balancing_B.INPUT_24_1_1[3];
  tmp_1[8] = 32;
  tmp_0[32] = robot_simple_balancing_B.INPUT_27_1_1[0];
  tmp_0[33] = robot_simple_balancing_B.INPUT_27_1_1[1];
  tmp_0[34] = robot_simple_balancing_B.INPUT_27_1_1[2];
  tmp_0[35] = robot_simple_balancing_B.INPUT_27_1_1[3];
  tmp_1[9] = 36;
  tmp_0[36] = robot_simple_balancing_B.INPUT_25_1_1[0];
  tmp_0[37] = robot_simple_balancing_B.INPUT_25_1_1[1];
  tmp_0[38] = robot_simple_balancing_B.INPUT_25_1_1[2];
  tmp_0[39] = robot_simple_balancing_B.INPUT_25_1_1[3];
  tmp_1[10] = 40;
  tmp_0[40] = robot_simple_balancing_B.INPUT_26_1_1[0];
  tmp_0[41] = robot_simple_balancing_B.INPUT_26_1_1[1];
  tmp_0[42] = robot_simple_balancing_B.INPUT_26_1_1[2];
  tmp_0[43] = robot_simple_balancing_B.INPUT_26_1_1[3];
  tmp_1[11] = 44;
  tmp_0[44] = robot_simple_balancing_B.INPUT_28_1_1[0];
  tmp_0[45] = robot_simple_balancing_B.INPUT_28_1_1[1];
  tmp_0[46] = robot_simple_balancing_B.INPUT_28_1_1[2];
  tmp_0[47] = robot_simple_balancing_B.INPUT_28_1_1[3];
  tmp_1[12] = 48;
  tmp_0[48] = robot_simple_balancing_B.INPUT_31_1_1[0];
  tmp_0[49] = robot_simple_balancing_B.INPUT_31_1_1[1];
  tmp_0[50] = robot_simple_balancing_B.INPUT_31_1_1[2];
  tmp_0[51] = robot_simple_balancing_B.INPUT_31_1_1[3];
  tmp_1[13] = 52;
  tmp_0[52] = robot_simple_balancing_B.INPUT_29_1_1[0];
  tmp_0[53] = robot_simple_balancing_B.INPUT_29_1_1[1];
  tmp_0[54] = robot_simple_balancing_B.INPUT_29_1_1[2];
  tmp_0[55] = robot_simple_balancing_B.INPUT_29_1_1[3];
  tmp_1[14] = 56;
  tmp_0[56] = robot_simple_balancing_B.INPUT_30_1_1[0];
  tmp_0[57] = robot_simple_balancing_B.INPUT_30_1_1[1];
  tmp_0[58] = robot_simple_balancing_B.INPUT_30_1_1[2];
  tmp_0[59] = robot_simple_balancing_B.INPUT_30_1_1[3];
  tmp_1[15] = 60;
  tmp_0[60] = robot_simple_balancing_B.INPUT_32_1_1[0];
  tmp_0[61] = robot_simple_balancing_B.INPUT_32_1_1[1];
  tmp_0[62] = robot_simple_balancing_B.INPUT_32_1_1[2];
  tmp_0[63] = robot_simple_balancing_B.INPUT_32_1_1[3];
  tmp_1[16] = 64;
  tmp_0[64] = robot_simple_balancing_B.INPUT_35_1_1[0];
  tmp_0[65] = robot_simple_balancing_B.INPUT_35_1_1[1];
  tmp_0[66] = robot_simple_balancing_B.INPUT_35_1_1[2];
  tmp_0[67] = robot_simple_balancing_B.INPUT_35_1_1[3];
  tmp_1[17] = 68;
  tmp_0[68] = robot_simple_balancing_B.INPUT_33_1_1[0];
  tmp_0[69] = robot_simple_balancing_B.INPUT_33_1_1[1];
  tmp_0[70] = robot_simple_balancing_B.INPUT_33_1_1[2];
  tmp_0[71] = robot_simple_balancing_B.INPUT_33_1_1[3];
  tmp_1[18] = 72;
  tmp_0[72] = robot_simple_balancing_B.INPUT_34_1_1[0];
  tmp_0[73] = robot_simple_balancing_B.INPUT_34_1_1[1];
  tmp_0[74] = robot_simple_balancing_B.INPUT_34_1_1[2];
  tmp_0[75] = robot_simple_balancing_B.INPUT_34_1_1[3];
  tmp_1[19] = 76;
  tmp_0[76] = robot_simple_balancing_B.INPUT_36_1_1[0];
  tmp_0[77] = robot_simple_balancing_B.INPUT_36_1_1[1];
  tmp_0[78] = robot_simple_balancing_B.INPUT_36_1_1[2];
  tmp_0[79] = robot_simple_balancing_B.INPUT_36_1_1[3];
  tmp_1[20] = 80;
  tmp_0[80] = robot_simple_balancing_B.INPUT_8_1_1[0];
  tmp_0[81] = robot_simple_balancing_B.INPUT_8_1_1[1];
  tmp_0[82] = robot_simple_balancing_B.INPUT_8_1_1[2];
  tmp_0[83] = robot_simple_balancing_B.INPUT_8_1_1[3];
  tmp_1[21] = 84;
  tmp_0[84] = robot_simple_balancing_B.INPUT_8_1_2[0];
  tmp_0[85] = robot_simple_balancing_B.INPUT_8_1_2[1];
  tmp_0[86] = robot_simple_balancing_B.INPUT_8_1_2[2];
  tmp_0[87] = robot_simple_balancing_B.INPUT_8_1_2[3];
  tmp_1[22] = 88;
  tmp_0[88] = robot_simple_balancing_B.INPUT_8_1_3[0];
  tmp_0[89] = robot_simple_balancing_B.INPUT_8_1_3[1];
  tmp_0[90] = robot_simple_balancing_B.INPUT_8_1_3[2];
  tmp_0[91] = robot_simple_balancing_B.INPUT_8_1_3[3];
  tmp_1[23] = 92;
  tmp_0[92] = robot_simple_balancing_B.INPUT_7_1_1[0];
  tmp_0[93] = robot_simple_balancing_B.INPUT_7_1_1[1];
  tmp_0[94] = robot_simple_balancing_B.INPUT_7_1_1[2];
  tmp_0[95] = robot_simple_balancing_B.INPUT_7_1_1[3];
  tmp_1[24] = 96;
  tmp_0[96] = robot_simple_balancing_B.INPUT_7_1_2[0];
  tmp_0[97] = robot_simple_balancing_B.INPUT_7_1_2[1];
  tmp_0[98] = robot_simple_balancing_B.INPUT_7_1_2[2];
  tmp_0[99] = robot_simple_balancing_B.INPUT_7_1_2[3];
  tmp_1[25] = 100;
  tmp_0[100] = robot_simple_balancing_B.INPUT_7_1_3[0];
  tmp_0[101] = robot_simple_balancing_B.INPUT_7_1_3[1];
  tmp_0[102] = robot_simple_balancing_B.INPUT_7_1_3[2];
  tmp_0[103] = robot_simple_balancing_B.INPUT_7_1_3[3];
  tmp_1[26] = 104;
  tmp_0[104] = robot_simple_balancing_B.INPUT_5_1_1[0];
  tmp_0[105] = robot_simple_balancing_B.INPUT_5_1_1[1];
  tmp_0[106] = robot_simple_balancing_B.INPUT_5_1_1[2];
  tmp_0[107] = robot_simple_balancing_B.INPUT_5_1_1[3];
  tmp_1[27] = 108;
  tmp_0[108] = robot_simple_balancing_B.INPUT_5_1_2[0];
  tmp_0[109] = robot_simple_balancing_B.INPUT_5_1_2[1];
  tmp_0[110] = robot_simple_balancing_B.INPUT_5_1_2[2];
  tmp_0[111] = robot_simple_balancing_B.INPUT_5_1_2[3];
  tmp_1[28] = 112;
  tmp_0[112] = robot_simple_balancing_B.INPUT_5_1_3[0];
  tmp_0[113] = robot_simple_balancing_B.INPUT_5_1_3[1];
  tmp_0[114] = robot_simple_balancing_B.INPUT_5_1_3[2];
  tmp_0[115] = robot_simple_balancing_B.INPUT_5_1_3[3];
  tmp_1[29] = 116;
  tmp_0[116] = robot_simple_balancing_B.INPUT_6_1_1[0];
  tmp_0[117] = robot_simple_balancing_B.INPUT_6_1_1[1];
  tmp_0[118] = robot_simple_balancing_B.INPUT_6_1_1[2];
  tmp_0[119] = robot_simple_balancing_B.INPUT_6_1_1[3];
  tmp_1[30] = 120;
  tmp_0[120] = robot_simple_balancing_B.INPUT_6_1_2[0];
  tmp_0[121] = robot_simple_balancing_B.INPUT_6_1_2[1];
  tmp_0[122] = robot_simple_balancing_B.INPUT_6_1_2[2];
  tmp_0[123] = robot_simple_balancing_B.INPUT_6_1_2[3];
  tmp_1[31] = 124;
  tmp_0[124] = robot_simple_balancing_B.INPUT_6_1_3[0];
  tmp_0[125] = robot_simple_balancing_B.INPUT_6_1_3[1];
  tmp_0[126] = robot_simple_balancing_B.INPUT_6_1_3[2];
  tmp_0[127] = robot_simple_balancing_B.INPUT_6_1_3[3];
  tmp_1[32] = 128;
  tmp_0[128] = robot_simple_balancing_B.INPUT_12_1_1[0];
  tmp_0[129] = robot_simple_balancing_B.INPUT_12_1_1[1];
  tmp_0[130] = robot_simple_balancing_B.INPUT_12_1_1[2];
  tmp_0[131] = robot_simple_balancing_B.INPUT_12_1_1[3];
  tmp_1[33] = 132;
  tmp_0[132] = robot_simple_balancing_B.INPUT_12_1_2[0];
  tmp_0[133] = robot_simple_balancing_B.INPUT_12_1_2[1];
  tmp_0[134] = robot_simple_balancing_B.INPUT_12_1_2[2];
  tmp_0[135] = robot_simple_balancing_B.INPUT_12_1_2[3];
  tmp_1[34] = 136;
  tmp_0[136] = robot_simple_balancing_B.INPUT_12_1_3[0];
  tmp_0[137] = robot_simple_balancing_B.INPUT_12_1_3[1];
  tmp_0[138] = robot_simple_balancing_B.INPUT_12_1_3[2];
  tmp_0[139] = robot_simple_balancing_B.INPUT_12_1_3[3];
  tmp_1[35] = 140;
  tmp_0[140] = robot_simple_balancing_B.INPUT_11_1_1[0];
  tmp_0[141] = robot_simple_balancing_B.INPUT_11_1_1[1];
  tmp_0[142] = robot_simple_balancing_B.INPUT_11_1_1[2];
  tmp_0[143] = robot_simple_balancing_B.INPUT_11_1_1[3];
  tmp_1[36] = 144;
  tmp_0[144] = robot_simple_balancing_B.INPUT_11_1_2[0];
  tmp_0[145] = robot_simple_balancing_B.INPUT_11_1_2[1];
  tmp_0[146] = robot_simple_balancing_B.INPUT_11_1_2[2];
  tmp_0[147] = robot_simple_balancing_B.INPUT_11_1_2[3];
  tmp_1[37] = 148;
  tmp_0[148] = robot_simple_balancing_B.INPUT_11_1_3[0];
  tmp_0[149] = robot_simple_balancing_B.INPUT_11_1_3[1];
  tmp_0[150] = robot_simple_balancing_B.INPUT_11_1_3[2];
  tmp_0[151] = robot_simple_balancing_B.INPUT_11_1_3[3];
  tmp_1[38] = 152;
  tmp_0[152] = robot_simple_balancing_B.INPUT_9_1_1[0];
  tmp_0[153] = robot_simple_balancing_B.INPUT_9_1_1[1];
  tmp_0[154] = robot_simple_balancing_B.INPUT_9_1_1[2];
  tmp_0[155] = robot_simple_balancing_B.INPUT_9_1_1[3];
  tmp_1[39] = 156;
  tmp_0[156] = robot_simple_balancing_B.INPUT_9_1_2[0];
  tmp_0[157] = robot_simple_balancing_B.INPUT_9_1_2[1];
  tmp_0[158] = robot_simple_balancing_B.INPUT_9_1_2[2];
  tmp_0[159] = robot_simple_balancing_B.INPUT_9_1_2[3];
  tmp_1[40] = 160;
  tmp_0[160] = robot_simple_balancing_B.INPUT_9_1_3[0];
  tmp_0[161] = robot_simple_balancing_B.INPUT_9_1_3[1];
  tmp_0[162] = robot_simple_balancing_B.INPUT_9_1_3[2];
  tmp_0[163] = robot_simple_balancing_B.INPUT_9_1_3[3];
  tmp_1[41] = 164;
  tmp_0[164] = robot_simple_balancing_B.INPUT_10_1_1[0];
  tmp_0[165] = robot_simple_balancing_B.INPUT_10_1_1[1];
  tmp_0[166] = robot_simple_balancing_B.INPUT_10_1_1[2];
  tmp_0[167] = robot_simple_balancing_B.INPUT_10_1_1[3];
  tmp_1[42] = 168;
  tmp_0[168] = robot_simple_balancing_B.INPUT_10_1_2[0];
  tmp_0[169] = robot_simple_balancing_B.INPUT_10_1_2[1];
  tmp_0[170] = robot_simple_balancing_B.INPUT_10_1_2[2];
  tmp_0[171] = robot_simple_balancing_B.INPUT_10_1_2[3];
  tmp_1[43] = 172;
  tmp_0[172] = robot_simple_balancing_B.INPUT_10_1_3[0];
  tmp_0[173] = robot_simple_balancing_B.INPUT_10_1_3[1];
  tmp_0[174] = robot_simple_balancing_B.INPUT_10_1_3[2];
  tmp_0[175] = robot_simple_balancing_B.INPUT_10_1_3[3];
  tmp_1[44] = 176;
  tmp_0[176] = robot_simple_balancing_B.INPUT_16_1_1[0];
  tmp_0[177] = robot_simple_balancing_B.INPUT_16_1_1[1];
  tmp_0[178] = robot_simple_balancing_B.INPUT_16_1_1[2];
  tmp_0[179] = robot_simple_balancing_B.INPUT_16_1_1[3];
  tmp_1[45] = 180;
  tmp_0[180] = robot_simple_balancing_B.INPUT_16_1_2[0];
  tmp_0[181] = robot_simple_balancing_B.INPUT_16_1_2[1];
  tmp_0[182] = robot_simple_balancing_B.INPUT_16_1_2[2];
  tmp_0[183] = robot_simple_balancing_B.INPUT_16_1_2[3];
  tmp_1[46] = 184;
  tmp_0[184] = robot_simple_balancing_B.INPUT_16_1_3[0];
  tmp_0[185] = robot_simple_balancing_B.INPUT_16_1_3[1];
  tmp_0[186] = robot_simple_balancing_B.INPUT_16_1_3[2];
  tmp_0[187] = robot_simple_balancing_B.INPUT_16_1_3[3];
  tmp_1[47] = 188;
  tmp_0[188] = robot_simple_balancing_B.INPUT_15_1_1[0];
  tmp_0[189] = robot_simple_balancing_B.INPUT_15_1_1[1];
  tmp_0[190] = robot_simple_balancing_B.INPUT_15_1_1[2];
  tmp_0[191] = robot_simple_balancing_B.INPUT_15_1_1[3];
  tmp_1[48] = 192;
  tmp_0[192] = robot_simple_balancing_B.INPUT_15_1_2[0];
  tmp_0[193] = robot_simple_balancing_B.INPUT_15_1_2[1];
  tmp_0[194] = robot_simple_balancing_B.INPUT_15_1_2[2];
  tmp_0[195] = robot_simple_balancing_B.INPUT_15_1_2[3];
  tmp_1[49] = 196;
  tmp_0[196] = robot_simple_balancing_B.INPUT_15_1_3[0];
  tmp_0[197] = robot_simple_balancing_B.INPUT_15_1_3[1];
  tmp_0[198] = robot_simple_balancing_B.INPUT_15_1_3[2];
  tmp_0[199] = robot_simple_balancing_B.INPUT_15_1_3[3];
  tmp_1[50] = 200;
  tmp_0[200] = robot_simple_balancing_B.INPUT_13_1_1[0];
  tmp_0[201] = robot_simple_balancing_B.INPUT_13_1_1[1];
  tmp_0[202] = robot_simple_balancing_B.INPUT_13_1_1[2];
  tmp_0[203] = robot_simple_balancing_B.INPUT_13_1_1[3];
  tmp_1[51] = 204;
  tmp_0[204] = robot_simple_balancing_B.INPUT_13_1_2[0];
  tmp_0[205] = robot_simple_balancing_B.INPUT_13_1_2[1];
  tmp_0[206] = robot_simple_balancing_B.INPUT_13_1_2[2];
  tmp_0[207] = robot_simple_balancing_B.INPUT_13_1_2[3];
  tmp_1[52] = 208;
  tmp_0[208] = robot_simple_balancing_B.INPUT_13_1_3[0];
  tmp_0[209] = robot_simple_balancing_B.INPUT_13_1_3[1];
  tmp_0[210] = robot_simple_balancing_B.INPUT_13_1_3[2];
  tmp_0[211] = robot_simple_balancing_B.INPUT_13_1_3[3];
  tmp_1[53] = 212;
  tmp_0[212] = robot_simple_balancing_B.INPUT_14_1_1[0];
  tmp_0[213] = robot_simple_balancing_B.INPUT_14_1_1[1];
  tmp_0[214] = robot_simple_balancing_B.INPUT_14_1_1[2];
  tmp_0[215] = robot_simple_balancing_B.INPUT_14_1_1[3];
  tmp_1[54] = 216;
  tmp_0[216] = robot_simple_balancing_B.INPUT_14_1_2[0];
  tmp_0[217] = robot_simple_balancing_B.INPUT_14_1_2[1];
  tmp_0[218] = robot_simple_balancing_B.INPUT_14_1_2[2];
  tmp_0[219] = robot_simple_balancing_B.INPUT_14_1_2[3];
  tmp_1[55] = 220;
  tmp_0[220] = robot_simple_balancing_B.INPUT_14_1_3[0];
  tmp_0[221] = robot_simple_balancing_B.INPUT_14_1_3[1];
  tmp_0[222] = robot_simple_balancing_B.INPUT_14_1_3[2];
  tmp_0[223] = robot_simple_balancing_B.INPUT_14_1_3[3];
  tmp_1[56] = 224;
  tmp_0[224] = robot_simple_balancing_B.INPUT_20_1_1[0];
  tmp_0[225] = robot_simple_balancing_B.INPUT_20_1_1[1];
  tmp_0[226] = robot_simple_balancing_B.INPUT_20_1_1[2];
  tmp_0[227] = robot_simple_balancing_B.INPUT_20_1_1[3];
  tmp_1[57] = 228;
  tmp_0[228] = robot_simple_balancing_B.INPUT_20_1_2[0];
  tmp_0[229] = robot_simple_balancing_B.INPUT_20_1_2[1];
  tmp_0[230] = robot_simple_balancing_B.INPUT_20_1_2[2];
  tmp_0[231] = robot_simple_balancing_B.INPUT_20_1_2[3];
  tmp_1[58] = 232;
  tmp_0[232] = robot_simple_balancing_B.INPUT_20_1_3[0];
  tmp_0[233] = robot_simple_balancing_B.INPUT_20_1_3[1];
  tmp_0[234] = robot_simple_balancing_B.INPUT_20_1_3[2];
  tmp_0[235] = robot_simple_balancing_B.INPUT_20_1_3[3];
  tmp_1[59] = 236;
  tmp_0[236] = robot_simple_balancing_B.INPUT_19_1_1[0];
  tmp_0[237] = robot_simple_balancing_B.INPUT_19_1_1[1];
  tmp_0[238] = robot_simple_balancing_B.INPUT_19_1_1[2];
  tmp_0[239] = robot_simple_balancing_B.INPUT_19_1_1[3];
  tmp_1[60] = 240;
  tmp_0[240] = robot_simple_balancing_B.INPUT_19_1_2[0];
  tmp_0[241] = robot_simple_balancing_B.INPUT_19_1_2[1];
  tmp_0[242] = robot_simple_balancing_B.INPUT_19_1_2[2];
  tmp_0[243] = robot_simple_balancing_B.INPUT_19_1_2[3];
  tmp_1[61] = 244;
  tmp_0[244] = robot_simple_balancing_B.INPUT_19_1_3[0];
  tmp_0[245] = robot_simple_balancing_B.INPUT_19_1_3[1];
  tmp_0[246] = robot_simple_balancing_B.INPUT_19_1_3[2];
  tmp_0[247] = robot_simple_balancing_B.INPUT_19_1_3[3];
  tmp_1[62] = 248;
  tmp_0[248] = robot_simple_balancing_B.INPUT_17_1_1[0];
  tmp_0[249] = robot_simple_balancing_B.INPUT_17_1_1[1];
  tmp_0[250] = robot_simple_balancing_B.INPUT_17_1_1[2];
  tmp_0[251] = robot_simple_balancing_B.INPUT_17_1_1[3];
  tmp_1[63] = 252;
  tmp_0[252] = robot_simple_balancing_B.INPUT_17_1_2[0];
  tmp_0[253] = robot_simple_balancing_B.INPUT_17_1_2[1];
  tmp_0[254] = robot_simple_balancing_B.INPUT_17_1_2[2];
  tmp_0[255] = robot_simple_balancing_B.INPUT_17_1_2[3];
  tmp_1[64] = 256;
  tmp_0[256] = robot_simple_balancing_B.INPUT_17_1_3[0];
  tmp_0[257] = robot_simple_balancing_B.INPUT_17_1_3[1];
  tmp_0[258] = robot_simple_balancing_B.INPUT_17_1_3[2];
  tmp_0[259] = robot_simple_balancing_B.INPUT_17_1_3[3];
  tmp_1[65] = 260;
  tmp_0[260] = robot_simple_balancing_B.INPUT_18_1_1[0];
  tmp_0[261] = robot_simple_balancing_B.INPUT_18_1_1[1];
  tmp_0[262] = robot_simple_balancing_B.INPUT_18_1_1[2];
  tmp_0[263] = robot_simple_balancing_B.INPUT_18_1_1[3];
  tmp_1[66] = 264;
  tmp_0[264] = robot_simple_balancing_B.INPUT_18_1_2[0];
  tmp_0[265] = robot_simple_balancing_B.INPUT_18_1_2[1];
  tmp_0[266] = robot_simple_balancing_B.INPUT_18_1_2[2];
  tmp_0[267] = robot_simple_balancing_B.INPUT_18_1_2[3];
  tmp_1[67] = 268;
  tmp_0[268] = robot_simple_balancing_B.INPUT_18_1_3[0];
  tmp_0[269] = robot_simple_balancing_B.INPUT_18_1_3[1];
  tmp_0[270] = robot_simple_balancing_B.INPUT_18_1_3[2];
  tmp_0[271] = robot_simple_balancing_B.INPUT_18_1_3[3];
  tmp_1[68] = 272;
  simulationData->mData->mInputValues.mN = 272;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 69;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 13;
  simulationData->mData->mDx.mX = &_rtXdot->robot_simple_balancingx6_DOF_Jo[0];
  diagnosticManager = (NeuDiagnosticManager *)
    robot_simple_balancing_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method((NeslSimulator *)
    robot_simple_balancing_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES,
    simulationData, diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(robot_simple_balancing_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S29>/STATE_1' */
}

/* Model initialize function */
void robot_simple_balancing_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  robot_simple_balancing_P.DeadZone_Start = rtMinusInf;
  robot_simple_balancing_P.Saturation_UpperSat = rtInf;
  robot_simple_balancing_P.DeadZone_Start_i = rtMinusInf;
  robot_simple_balancing_P.Saturation_UpperSat_b = rtInf;
  robot_simple_balancing_P.DeadZone_Start_e = rtMinusInf;
  robot_simple_balancing_P.Saturation_UpperSat_j = rtInf;
  robot_simple_balancing_P.DeadZone_Start_f = rtMinusInf;
  robot_simple_balancing_P.Saturation_UpperSat_k = rtInf;

  /* initialize real-time model */
  (void) memset((void *)robot_simple_balancing_M, 0,
                sizeof(RT_MODEL_robot_simple_balanci_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&robot_simple_balancing_M->solverInfo,
                          &robot_simple_balancing_M->Timing.simTimeStep);
    rtsiSetTPtr(&robot_simple_balancing_M->solverInfo, &rtmGetTPtr
                (robot_simple_balancing_M));
    rtsiSetStepSizePtr(&robot_simple_balancing_M->solverInfo,
                       &robot_simple_balancing_M->Timing.stepSize0);
    rtsiSetdXPtr(&robot_simple_balancing_M->solverInfo,
                 &robot_simple_balancing_M->derivs);
    rtsiSetContStatesPtr(&robot_simple_balancing_M->solverInfo, (real_T **)
                         &robot_simple_balancing_M->contStates);
    rtsiSetNumContStatesPtr(&robot_simple_balancing_M->solverInfo,
      &robot_simple_balancing_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&robot_simple_balancing_M->solverInfo,
      &robot_simple_balancing_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&robot_simple_balancing_M->solverInfo,
      &robot_simple_balancing_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&robot_simple_balancing_M->solverInfo,
      &robot_simple_balancing_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&robot_simple_balancing_M->solverInfo,
                          (&rtmGetErrorStatus(robot_simple_balancing_M)));
    rtsiSetRTModelPtr(&robot_simple_balancing_M->solverInfo,
                      robot_simple_balancing_M);
  }

  rtsiSetSimTimeStep(&robot_simple_balancing_M->solverInfo, MAJOR_TIME_STEP);
  robot_simple_balancing_M->intgData.y = robot_simple_balancing_M->odeY;
  robot_simple_balancing_M->intgData.f[0] = robot_simple_balancing_M->odeF[0];
  robot_simple_balancing_M->intgData.f[1] = robot_simple_balancing_M->odeF[1];
  robot_simple_balancing_M->intgData.f[2] = robot_simple_balancing_M->odeF[2];
  robot_simple_balancing_M->intgData.f[3] = robot_simple_balancing_M->odeF[3];
  robot_simple_balancing_M->contStates = ((X_robot_simple_balancing_T *)
    &robot_simple_balancing_X);
  rtsiSetSolverData(&robot_simple_balancing_M->solverInfo, (void *)
                    &robot_simple_balancing_M->intgData);
  rtsiSetSolverName(&robot_simple_balancing_M->solverInfo,"ode4");
  rtmSetTPtr(robot_simple_balancing_M, &robot_simple_balancing_M->Timing.tArray
             [0]);
  rtmSetTFinal(robot_simple_balancing_M, 10.0);
  robot_simple_balancing_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    robot_simple_balancing_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(robot_simple_balancing_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(robot_simple_balancing_M->rtwLogInfo, (NULL));
    rtliSetLogT(robot_simple_balancing_M->rtwLogInfo, "tout");
    rtliSetLogX(robot_simple_balancing_M->rtwLogInfo, "");
    rtliSetLogXFinal(robot_simple_balancing_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(robot_simple_balancing_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(robot_simple_balancing_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(robot_simple_balancing_M->rtwLogInfo, 0);
    rtliSetLogDecimation(robot_simple_balancing_M->rtwLogInfo, 1);
    rtliSetLogY(robot_simple_balancing_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(robot_simple_balancing_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(robot_simple_balancing_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &robot_simple_balancing_B), 0,
                sizeof(B_robot_simple_balancing_T));

  /* states (continuous) */
  {
    (void) memset((void *)&robot_simple_balancing_X, 0,
                  sizeof(X_robot_simple_balancing_T));
  }

  /* states (dwork) */
  (void) memset((void *)&robot_simple_balancing_DW, 0,
                sizeof(DW_robot_simple_balancing_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(robot_simple_balancing_M->rtwLogInfo, 0.0,
    rtmGetTFinal(robot_simple_balancing_M),
    robot_simple_balancing_M->Timing.stepSize0, (&rtmGetErrorStatus
    (robot_simple_balancing_M)));

  {
    NeslSimulator *tmp;
    boolean_T tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeModelParameters modelParameters;
    real_T tmp_1;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp_3;
    NeModelParameters modelParameters_0;
    real_T time_0;
    NeParameterBundle expl_temp;
    real_T time_tmp;

    /* Start for SimscapeExecutionBlock: '<S29>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S29>/OUTPUT_1_0'
     */
    tmp = nesl_lease_simulator("robot_simple_balancing/Solver Configuration_1",
      0, 0);
    robot_simple_balancing_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(robot_simple_balancing_DW.STATE_1_Simulator);
    if (tmp_0) {
      robot_simple_balancing_f30145f9_1_gateway();
      tmp = nesl_lease_simulator("robot_simple_balancing/Solver Configuration_1",
        0, 0);
      robot_simple_balancing_DW.STATE_1_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    robot_simple_balancing_DW.STATE_1_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    robot_simple_balancing_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 5.04975741E+8;
    tmp_1 = 0.001;
    modelParameters.mSolverTolerance = tmp_1;
    tmp_1 = 0.001;
    modelParameters.mFixedStepSize = tmp_1;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)
      robot_simple_balancing_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    expl_temp.mRealParameters.mN = 0;
    expl_temp.mRealParameters.mX = NULL;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    nesl_simulator_set_rtps((NeslSimulator *)
      robot_simple_balancing_DW.STATE_1_Simulator, expl_temp);
    simulationData = (NeslSimulationData *)
      robot_simple_balancing_DW.STATE_1_SimData;
    time_tmp = robot_simple_balancing_M->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 13;
    simulationData->mData->mContStates.mX =
      &robot_simple_balancing_X.robot_simple_balancingx6_DOF_Jo[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &robot_simple_balancing_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &robot_simple_balancing_DW.STATE_1_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    tmp_0 = rtmIsMajorTimeStep(robot_simple_balancing_M);
    simulationData->mData->mIsMajorTimeStep = tmp_0;
    tmp_3 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_3;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_3 = rtsiIsSolverComputingJacobian(&robot_simple_balancing_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_3;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      robot_simple_balancing_DW.STATE_1_Simulator, NESL_SIM_INITIALIZEONCE,
      simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp_3) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S29>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S29>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("robot_simple_balancing/Solver Configuration_1",
      1, 0);
    robot_simple_balancing_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_3 = pointer_is_null(robot_simple_balancing_DW.OUTPUT_1_0_Simulator);
    if (tmp_3) {
      robot_simple_balancing_f30145f9_1_gateway();
      tmp = nesl_lease_simulator("robot_simple_balancing/Solver Configuration_1",
        1, 0);
      robot_simple_balancing_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    robot_simple_balancing_DW.OUTPUT_1_0_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    robot_simple_balancing_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 5.04975741E+8;
    tmp_1 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_1;
    tmp_1 = 0.001;
    modelParameters_0.mFixedStepSize = tmp_1;
    tmp_3 = false;
    modelParameters_0.mVariableStepSolver = tmp_3;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)
      robot_simple_balancing_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp_3) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)
      robot_simple_balancing_DW.OUTPUT_1_0_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &robot_simple_balancing_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX =
      &robot_simple_balancing_DW.OUTPUT_1_0_Modes;
    tmp_3 = false;
    simulationData->mData->mFoundZcEvents = tmp_3;
    simulationData->mData->mIsMajorTimeStep = tmp_0;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)
      robot_simple_balancing_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      robot_simple_balancing_DW.OUTPUT_1_0_Simulator, NESL_SIM_INITIALIZEONCE,
      simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(robot_simple_balancing_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(robot_simple_balancing_M, msg);
      }
    }

    /* Start for If: '<S12>/If1' */
    robot_simple_balancing_DW.If1_ActiveSubsystem = -1;

    /* Start for If: '<S13>/If1' */
    robot_simple_balancing_DW.If1_ActiveSubsystem_p = -1;

    /* Start for If: '<S14>/If1' */
    robot_simple_balancing_DW.If1_ActiveSubsystem_e = -1;

    /* Start for If: '<S15>/If1' */
    robot_simple_balancing_DW.If1_ActiveSubsystem_a = -1;
  }

  {
    boolean_T tmp;
    char *tmp_0;
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    for (i = 0; i < 9; i++) {
      robot_simple_balancing_DW.Delay_DSTATE[i] =
        robot_simple_balancing_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay' */

    /* InitializeConditions for SimscapeExecutionBlock: '<S29>/STATE_1' */
    tmp = false;
    if (tmp) {
      i = strcmp("ode4", rtsiGetSolverName(&robot_simple_balancing_M->solverInfo));
      if (i != 0) {
        tmp_0 = solver_mismatch_message("ode4", rtsiGetSolverName
          (&robot_simple_balancing_M->solverInfo));
        rtmSetErrorStatus(robot_simple_balancing_M, tmp_0);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S29>/STATE_1' */
    for (i = 0; i < 12; i++) {
      /* SystemInitialize for Merge: '<S12>/Merge' */
      robot_simple_balancing_B.FSph[i] =
        robot_simple_balancing_P.Merge_InitialOutput;

      /* SystemInitialize for Merge: '<S13>/Merge' */
      robot_simple_balancing_B.FSph_f[i] =
        robot_simple_balancing_P.Merge_InitialOutput_o;

      /* SystemInitialize for Merge: '<S14>/Merge' */
      robot_simple_balancing_B.FSph_n[i] =
        robot_simple_balancing_P.Merge_InitialOutput_d;

      /* SystemInitialize for Merge: '<S15>/Merge' */
      robot_simple_balancing_B.FSph_fe[i] =
        robot_simple_balancing_P.Merge_InitialOutput_h;
    }
  }
}

/* Model terminate function */
void robot_simple_balancing_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S29>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    robot_simple_balancing_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    robot_simple_balancing_DW.STATE_1_SimData);
  nesl_erase_simulator("robot_simple_balancing/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S29>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    robot_simple_balancing_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    robot_simple_balancing_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("robot_simple_balancing/Solver Configuration_1");
}
