/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'robot_simple_balancing/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "sm_CTarget.h"

void robot_simple_balancing_f30145f9_1_setTargets(const
  RuntimeDerivedValuesBundle *rtdv, CTarget *targets)
{
  (void) rtdv;
  (void) targets;
}

void robot_simple_balancing_f30145f9_1_resetAsmStateVector(const void *mech,
  double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = 1.0;
  state[4] = xx[0];
  state[5] = xx[0];
  state[6] = xx[0];
  state[7] = xx[0];
  state[8] = xx[0];
  state[9] = xx[0];
  state[10] = xx[0];
  state[11] = xx[0];
  state[12] = xx[0];
  state[13] = xx[0];
  state[14] = xx[0];
  state[15] = xx[0];
  state[16] = xx[0];
  state[17] = xx[0];
  state[18] = xx[0];
  state[19] = xx[0];
  state[20] = xx[0];
  state[21] = xx[0];
  state[22] = xx[0];
  state[23] = xx[0];
  state[24] = xx[0];
  state[25] = xx[0];
  state[26] = xx[0];
  state[27] = xx[0];
  state[28] = xx[0];
  state[29] = xx[0];
  state[30] = xx[0];
  state[31] = xx[0];
  state[32] = xx[0];
  state[33] = xx[0];
  state[34] = xx[0];
  state[35] = xx[0];
  state[36] = xx[0];
  state[37] = xx[0];
  state[38] = xx[0];
  state[39] = xx[0];
  state[40] = xx[0];
  state[41] = xx[0];
  state[42] = xx[0];
  state[43] = xx[0];
  state[44] = xx[0];
  state[45] = xx[0];
  state[46] = xx[0];
  state[47] = xx[0];
  state[48] = xx[0];
  state[49] = xx[0];
  state[50] = xx[0];
  state[51] = xx[0];
  state[52] = xx[0];
}

void robot_simple_balancing_f30145f9_1_initializeTrackedAngleState(const void
  *mech, const RuntimeDerivedValuesBundle *rtdv, const int *modeVector, const
  double *motionData, double *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) rtdv;
  (void) modeVector;
  (void) motionData;
  (void) state;
  (void) neDiagMgr;
}

void robot_simple_balancing_f30145f9_1_computeDiscreteState(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, double *state)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
}

void robot_simple_balancing_f30145f9_1_adjustPosition(const void *mech, const
  double *dofDeltas, double *state)
{
  double xx[11];
  (void) mech;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = dofDeltas[3];
  xx[5] = dofDeltas[4];
  xx[6] = dofDeltas[5];
  pm_math_Quaternion_compDeriv_ra(xx + 0, xx + 4, xx + 7);
  xx[0] = state[3] + xx[7];
  xx[1] = state[4] + xx[8];
  xx[2] = state[5] + xx[9];
  xx[3] = state[6] + xx[10];
  xx[4] = sqrt(xx[0] * xx[0] + xx[1] * xx[1] + xx[2] * xx[2] + xx[3] * xx[3]);
  xx[5] = 1.0e-64;
  if (xx[5] > xx[4])
    xx[4] = xx[5];
  state[0] = state[0] + dofDeltas[0];
  state[1] = state[1] + dofDeltas[1];
  state[2] = state[2] + dofDeltas[2];
  state[3] = xx[0] / xx[4];
  state[4] = xx[1] / xx[4];
  state[5] = xx[2] / xx[4];
  state[6] = xx[3] / xx[4];
  state[13] = state[13] + dofDeltas[6];
  state[14] = state[14] + dofDeltas[7];
  state[15] = state[15] + dofDeltas[8];
  state[19] = state[19] + dofDeltas[9];
  state[21] = state[21] + dofDeltas[10];
  state[22] = state[22] + dofDeltas[11];
  state[23] = state[23] + dofDeltas[12];
  state[27] = state[27] + dofDeltas[13];
  state[29] = state[29] + dofDeltas[14];
  state[30] = state[30] + dofDeltas[15];
  state[31] = state[31] + dofDeltas[16];
  state[35] = state[35] + dofDeltas[17];
  state[37] = state[37] + dofDeltas[18];
  state[38] = state[38] + dofDeltas[19];
  state[39] = state[39] + dofDeltas[20];
  state[43] = state[43] + dofDeltas[21];
  state[45] = state[45] + dofDeltas[22];
  state[47] = state[47] + dofDeltas[23];
  state[48] = state[48] + dofDeltas[24];
  state[49] = state[49] + dofDeltas[25];
}

static void perturbAsmJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbAsmJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[7] = state[7] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbAsmJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[8] = state[8] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbAsmJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[9] = state[9] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_0_3(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 0, xx + 4);
  state[3] = xx[4];
  state[4] = xx[5];
  state[5] = xx[6];
  state[6] = xx[7];
}

static void perturbAsmJointPrimitiveState_0_3v(double mag, double *state)
{
  double xx[15];
  xx[0] = 1.0;
  xx[1] = fabs(mag);
  xx[2] = xx[0] / (xx[1] - floor(xx[1]) + 1.0e-9);
  xx[1] = sin(xx[2]);
  xx[3] = 0.0;
  xx[4] = cos(xx[2]);
  xx[5] = sin(2.0 * xx[2]);
  xx[2] = 0.5 * mag;
  xx[6] = sqrt(xx[1] * xx[1] + xx[4] * xx[4] + xx[5] * xx[5]);
  xx[7] = xx[6] == 0.0 ? 0.0 : xx[1] / xx[6];
  xx[8] = sin(xx[2]);
  xx[9] = xx[6] == 0.0 ? 0.0 : xx[4] / xx[6];
  xx[10] = xx[6] == 0.0 ? 0.0 : xx[5] / xx[6];
  xx[11] = xx[1] == xx[3] && xx[4] == xx[3] && xx[5] == xx[3] ? xx[0] : cos(xx[2]);
  xx[12] = xx[7] * xx[8];
  xx[13] = xx[9] * xx[8];
  xx[14] = xx[10] * xx[8];
  xx[3] = state[3];
  xx[4] = state[4];
  xx[5] = state[5];
  xx[6] = state[6];
  pm_math_Quaternion_compose_ra(xx + 11, xx + 3, xx + 7);
  state[3] = xx[7];
  state[4] = xx[8];
  state[5] = xx[9];
  state[6] = xx[10];
  state[10] = state[10] + 1.2 * mag;
  state[11] = state[11] - xx[2];
  state[12] = state[12] + 0.9 * mag;
}

static void perturbAsmJointPrimitiveState_1_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbAsmJointPrimitiveState_1_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[16] = state[16] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_1(double mag, double *state)
{
  state[14] = state[14] + mag;
}

static void perturbAsmJointPrimitiveState_1_1v(double mag, double *state)
{
  state[14] = state[14] + mag;
  state[17] = state[17] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_1_2(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbAsmJointPrimitiveState_1_2v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[18] = state[18] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_2_0(double mag, double *state)
{
  state[19] = state[19] + mag;
}

static void perturbAsmJointPrimitiveState_2_0v(double mag, double *state)
{
  state[19] = state[19] + mag;
  state[20] = state[20] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_3_0(double mag, double *state)
{
  state[21] = state[21] + mag;
}

static void perturbAsmJointPrimitiveState_3_0v(double mag, double *state)
{
  state[21] = state[21] + mag;
  state[24] = state[24] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_3_1(double mag, double *state)
{
  state[22] = state[22] + mag;
}

static void perturbAsmJointPrimitiveState_3_1v(double mag, double *state)
{
  state[22] = state[22] + mag;
  state[25] = state[25] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_3_2(double mag, double *state)
{
  state[23] = state[23] + mag;
}

static void perturbAsmJointPrimitiveState_3_2v(double mag, double *state)
{
  state[23] = state[23] + mag;
  state[26] = state[26] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_4_0(double mag, double *state)
{
  state[27] = state[27] + mag;
}

static void perturbAsmJointPrimitiveState_4_0v(double mag, double *state)
{
  state[27] = state[27] + mag;
  state[28] = state[28] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_0(double mag, double *state)
{
  state[29] = state[29] + mag;
}

static void perturbAsmJointPrimitiveState_5_0v(double mag, double *state)
{
  state[29] = state[29] + mag;
  state[32] = state[32] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_1(double mag, double *state)
{
  state[30] = state[30] + mag;
}

static void perturbAsmJointPrimitiveState_5_1v(double mag, double *state)
{
  state[30] = state[30] + mag;
  state[33] = state[33] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_5_2(double mag, double *state)
{
  state[31] = state[31] + mag;
}

static void perturbAsmJointPrimitiveState_5_2v(double mag, double *state)
{
  state[31] = state[31] + mag;
  state[34] = state[34] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_6_0(double mag, double *state)
{
  state[35] = state[35] + mag;
}

static void perturbAsmJointPrimitiveState_6_0v(double mag, double *state)
{
  state[35] = state[35] + mag;
  state[36] = state[36] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_7_0(double mag, double *state)
{
  state[37] = state[37] + mag;
}

static void perturbAsmJointPrimitiveState_7_0v(double mag, double *state)
{
  state[37] = state[37] + mag;
  state[40] = state[40] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_7_1(double mag, double *state)
{
  state[38] = state[38] + mag;
}

static void perturbAsmJointPrimitiveState_7_1v(double mag, double *state)
{
  state[38] = state[38] + mag;
  state[41] = state[41] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_7_2(double mag, double *state)
{
  state[39] = state[39] + mag;
}

static void perturbAsmJointPrimitiveState_7_2v(double mag, double *state)
{
  state[39] = state[39] + mag;
  state[42] = state[42] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_8_0(double mag, double *state)
{
  state[43] = state[43] + mag;
}

static void perturbAsmJointPrimitiveState_8_0v(double mag, double *state)
{
  state[43] = state[43] + mag;
  state[44] = state[44] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_9_0(double mag, double *state)
{
  state[45] = state[45] + mag;
}

static void perturbAsmJointPrimitiveState_9_0v(double mag, double *state)
{
  state[45] = state[45] + mag;
  state[46] = state[46] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_10_0(double mag, double *state)
{
  state[47] = state[47] + mag;
}

static void perturbAsmJointPrimitiveState_10_0v(double mag, double *state)
{
  state[47] = state[47] + mag;
  state[50] = state[50] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_10_1(double mag, double *state)
{
  state[48] = state[48] + mag;
}

static void perturbAsmJointPrimitiveState_10_1v(double mag, double *state)
{
  state[48] = state[48] + mag;
  state[51] = state[51] - 0.875 * mag;
}

static void perturbAsmJointPrimitiveState_10_2(double mag, double *state)
{
  state[49] = state[49] + mag;
}

static void perturbAsmJointPrimitiveState_10_2v(double mag, double *state)
{
  state[49] = state[49] + mag;
  state[52] = state[52] - 0.875 * mag;
}

void robot_simple_balancing_f30145f9_1_perturbAsmJointPrimitiveState(const void *
  mech, size_t stageIdx, size_t primIdx, double mag, boolean_T doPerturbVelocity,
  double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbAsmJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbAsmJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbAsmJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbAsmJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbAsmJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbAsmJointPrimitiveState_0_2v(mag, state);
    break;

   case 6:
    perturbAsmJointPrimitiveState_0_3(mag, state);
    break;

   case 7:
    perturbAsmJointPrimitiveState_0_3v(mag, state);
    break;

   case 12:
    perturbAsmJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbAsmJointPrimitiveState_1_0v(mag, state);
    break;

   case 14:
    perturbAsmJointPrimitiveState_1_1(mag, state);
    break;

   case 15:
    perturbAsmJointPrimitiveState_1_1v(mag, state);
    break;

   case 16:
    perturbAsmJointPrimitiveState_1_2(mag, state);
    break;

   case 17:
    perturbAsmJointPrimitiveState_1_2v(mag, state);
    break;

   case 24:
    perturbAsmJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbAsmJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbAsmJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbAsmJointPrimitiveState_3_0v(mag, state);
    break;

   case 38:
    perturbAsmJointPrimitiveState_3_1(mag, state);
    break;

   case 39:
    perturbAsmJointPrimitiveState_3_1v(mag, state);
    break;

   case 40:
    perturbAsmJointPrimitiveState_3_2(mag, state);
    break;

   case 41:
    perturbAsmJointPrimitiveState_3_2v(mag, state);
    break;

   case 48:
    perturbAsmJointPrimitiveState_4_0(mag, state);
    break;

   case 49:
    perturbAsmJointPrimitiveState_4_0v(mag, state);
    break;

   case 60:
    perturbAsmJointPrimitiveState_5_0(mag, state);
    break;

   case 61:
    perturbAsmJointPrimitiveState_5_0v(mag, state);
    break;

   case 62:
    perturbAsmJointPrimitiveState_5_1(mag, state);
    break;

   case 63:
    perturbAsmJointPrimitiveState_5_1v(mag, state);
    break;

   case 64:
    perturbAsmJointPrimitiveState_5_2(mag, state);
    break;

   case 65:
    perturbAsmJointPrimitiveState_5_2v(mag, state);
    break;

   case 72:
    perturbAsmJointPrimitiveState_6_0(mag, state);
    break;

   case 73:
    perturbAsmJointPrimitiveState_6_0v(mag, state);
    break;

   case 84:
    perturbAsmJointPrimitiveState_7_0(mag, state);
    break;

   case 85:
    perturbAsmJointPrimitiveState_7_0v(mag, state);
    break;

   case 86:
    perturbAsmJointPrimitiveState_7_1(mag, state);
    break;

   case 87:
    perturbAsmJointPrimitiveState_7_1v(mag, state);
    break;

   case 88:
    perturbAsmJointPrimitiveState_7_2(mag, state);
    break;

   case 89:
    perturbAsmJointPrimitiveState_7_2v(mag, state);
    break;

   case 96:
    perturbAsmJointPrimitiveState_8_0(mag, state);
    break;

   case 97:
    perturbAsmJointPrimitiveState_8_0v(mag, state);
    break;

   case 108:
    perturbAsmJointPrimitiveState_9_0(mag, state);
    break;

   case 109:
    perturbAsmJointPrimitiveState_9_0v(mag, state);
    break;

   case 120:
    perturbAsmJointPrimitiveState_10_0(mag, state);
    break;

   case 121:
    perturbAsmJointPrimitiveState_10_0v(mag, state);
    break;

   case 122:
    perturbAsmJointPrimitiveState_10_1(mag, state);
    break;

   case 123:
    perturbAsmJointPrimitiveState_10_1v(mag, state);
    break;

   case 124:
    perturbAsmJointPrimitiveState_10_2(mag, state);
    break;

   case 125:
    perturbAsmJointPrimitiveState_10_2v(mag, state);
    break;
  }
}

void robot_simple_balancing_f30145f9_1_computeDofBlendMatrix(const void *mech,
  size_t stageIdx, size_t primIdx, const double *state, int partialType, double *
  matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void robot_simple_balancing_f30145f9_1_projectPartiallyTargetedPos(const void
  *mech, size_t stageIdx, size_t primIdx, const double *origState, int
  partialType, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void robot_simple_balancing_f30145f9_1_propagateMotion(const void *mech, const
  RuntimeDerivedValuesBundle *rtdv, const double *state, double *motionData)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[129];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  xx[0] = - state[3];
  xx[1] = - state[4];
  xx[2] = - state[5];
  xx[3] = - state[6];
  xx[4] = state[2] + 0.8;
  xx[5] = 0.5;
  xx[6] = xx[5] * state[15];
  xx[7] = cos(xx[6]);
  xx[8] = xx[5] * state[14];
  xx[9] = cos(xx[8]);
  xx[10] = xx[5] * state[13];
  xx[11] = sin(xx[10]);
  xx[12] = xx[9] * xx[11];
  xx[13] = cos(xx[10]);
  xx[10] = sin(xx[8]);
  xx[8] = xx[13] * xx[10];
  xx[14] = sin(xx[6]);
  xx[6] = xx[7] * xx[12] + xx[8] * xx[14];
  xx[15] = xx[11] * xx[10];
  xx[10] = xx[13] * xx[9];
  xx[9] = xx[15] * xx[14] - xx[7] * xx[10];
  xx[11] = xx[7] * xx[15] + xx[10] * xx[14];
  xx[10] = xx[12] * xx[14] - xx[7] * xx[8];
  xx[8] = 0.3;
  xx[12] = 0.05;
  xx[13] = xx[11] * xx[12];
  xx[15] = xx[12] * xx[9];
  xx[16] = 2.0;
  xx[17] = xx[8] - (xx[6] * xx[13] + xx[15] * xx[10]) * xx[16];
  xx[18] = 0.2;
  xx[19] = - (xx[18] + xx[16] * (xx[13] * xx[10] - xx[6] * xx[15]));
  xx[20] = - (xx[12] - (xx[15] * xx[9] + xx[11] * xx[13]) * xx[16]);
  xx[13] = 1.0;
  xx[15] = - xx[13];
  xx[21] = 0.0;
  xx[22] = state[19] - xx[12];
  xx[23] = xx[5] * state[23];
  xx[24] = cos(xx[23]);
  xx[25] = xx[5] * state[22];
  xx[26] = cos(xx[25]);
  xx[27] = xx[5] * state[21];
  xx[28] = sin(xx[27]);
  xx[29] = xx[26] * xx[28];
  xx[30] = cos(xx[27]);
  xx[27] = sin(xx[25]);
  xx[25] = xx[30] * xx[27];
  xx[31] = sin(xx[23]);
  xx[23] = xx[24] * xx[29] + xx[25] * xx[31];
  xx[32] = xx[28] * xx[27];
  xx[27] = xx[30] * xx[26];
  xx[26] = xx[32] * xx[31] - xx[24] * xx[27];
  xx[28] = xx[24] * xx[32] + xx[27] * xx[31];
  xx[27] = xx[29] * xx[31] - xx[24] * xx[25];
  xx[25] = xx[28] * xx[12];
  xx[29] = xx[12] * xx[26];
  xx[30] = xx[8] - (xx[23] * xx[25] + xx[29] * xx[27]) * xx[16];
  xx[32] = xx[18] - xx[16] * (xx[25] * xx[27] - xx[23] * xx[29]);
  xx[33] = - (xx[12] - (xx[29] * xx[26] + xx[28] * xx[25]) * xx[16]);
  xx[25] = state[27] - xx[12];
  xx[29] = xx[5] * state[31];
  xx[34] = cos(xx[29]);
  xx[35] = xx[5] * state[30];
  xx[36] = cos(xx[35]);
  xx[37] = xx[5] * state[29];
  xx[38] = sin(xx[37]);
  xx[39] = xx[36] * xx[38];
  xx[40] = cos(xx[37]);
  xx[37] = sin(xx[35]);
  xx[35] = xx[40] * xx[37];
  xx[41] = sin(xx[29]);
  xx[29] = xx[34] * xx[39] + xx[35] * xx[41];
  xx[42] = xx[38] * xx[37];
  xx[37] = xx[40] * xx[36];
  xx[36] = xx[42] * xx[41] - xx[34] * xx[37];
  xx[38] = xx[34] * xx[42] + xx[37] * xx[41];
  xx[37] = xx[39] * xx[41] - xx[34] * xx[35];
  xx[35] = xx[38] * xx[12];
  xx[39] = xx[12] * xx[36];
  xx[40] = - (xx[8] + (xx[29] * xx[35] + xx[39] * xx[37]) * xx[16]);
  xx[42] = - (xx[18] + xx[16] * (xx[35] * xx[37] - xx[29] * xx[39]));
  xx[43] = - (xx[12] - (xx[39] * xx[36] + xx[38] * xx[35]) * xx[16]);
  xx[35] = state[35] - xx[12];
  xx[39] = xx[5] * state[39];
  xx[44] = cos(xx[39]);
  xx[45] = xx[5] * state[38];
  xx[46] = cos(xx[45]);
  xx[47] = xx[5] * state[37];
  xx[48] = sin(xx[47]);
  xx[49] = xx[46] * xx[48];
  xx[50] = cos(xx[47]);
  xx[47] = sin(xx[45]);
  xx[45] = xx[50] * xx[47];
  xx[51] = sin(xx[39]);
  xx[39] = xx[44] * xx[49] + xx[45] * xx[51];
  xx[52] = xx[48] * xx[47];
  xx[47] = xx[50] * xx[46];
  xx[46] = xx[52] * xx[51] - xx[44] * xx[47];
  xx[48] = xx[44] * xx[52] + xx[47] * xx[51];
  xx[47] = xx[49] * xx[51] - xx[44] * xx[45];
  xx[45] = xx[48] * xx[12];
  xx[49] = xx[12] * xx[46];
  xx[50] = - (xx[8] + (xx[39] * xx[45] + xx[49] * xx[47]) * xx[16]);
  xx[8] = xx[18] - xx[16] * (xx[45] * xx[47] - xx[39] * xx[49]);
  xx[18] = - (xx[12] - (xx[49] * xx[46] + xx[48] * xx[45]) * xx[16]);
  xx[45] = state[43] - xx[12];
  xx[49] = xx[5] * state[45];
  xx[52] = xx[6];
  xx[53] = xx[9];
  xx[54] = xx[11];
  xx[55] = xx[10];
  pm_math_Quaternion_compose_ra(xx + 0, xx + 52, xx + 56);
  xx[60] = xx[17];
  xx[61] = xx[19];
  xx[62] = xx[20];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 60, xx + 63);
  xx[5] = xx[63] + state[0];
  xx[66] = xx[64] + state[1];
  xx[63] = xx[65] + xx[4];
  xx[64] = xx[22] * xx[58];
  xx[65] = xx[22] * xx[57];
  xx[67] = xx[23];
  xx[68] = xx[26];
  xx[69] = xx[28];
  xx[70] = xx[27];
  pm_math_Quaternion_compose_ra(xx + 0, xx + 67, xx + 71);
  xx[75] = xx[30];
  xx[76] = xx[32];
  xx[77] = xx[33];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 75, xx + 78);
  xx[81] = xx[78] + state[0];
  xx[82] = xx[79] + state[1];
  xx[78] = xx[80] + xx[4];
  xx[79] = xx[25] * xx[73];
  xx[80] = xx[25] * xx[72];
  xx[83] = xx[29];
  xx[84] = xx[36];
  xx[85] = xx[38];
  xx[86] = xx[37];
  pm_math_Quaternion_compose_ra(xx + 0, xx + 83, xx + 87);
  xx[91] = xx[40];
  xx[92] = xx[42];
  xx[93] = xx[43];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 91, xx + 94);
  xx[97] = xx[94] + state[0];
  xx[98] = xx[95] + state[1];
  xx[94] = xx[96] + xx[4];
  xx[95] = xx[35] * xx[89];
  xx[96] = xx[35] * xx[88];
  xx[99] = xx[39];
  xx[100] = xx[46];
  xx[101] = xx[48];
  xx[102] = xx[47];
  pm_math_Quaternion_compose_ra(xx + 0, xx + 99, xx + 103);
  xx[107] = xx[50];
  xx[108] = xx[8];
  xx[109] = xx[18];
  pm_math_Quaternion_xform_ra(xx + 0, xx + 107, xx + 110);
  xx[113] = xx[110] + state[0];
  xx[114] = xx[111] + state[1];
  xx[110] = xx[112] + xx[4];
  xx[111] = xx[45] * xx[105];
  xx[112] = xx[45] * xx[104];
  xx[115] = state[7];
  xx[116] = state[8];
  xx[117] = state[9];
  pm_math_Quaternion_inverseXform_ra(xx + 0, xx + 115, xx + 118);
  xx[115] = state[10];
  xx[116] = state[11];
  xx[117] = state[12];
  pm_math_Quaternion_inverseXform_ra(xx + 52, xx + 115, xx + 121);
  xx[124] = (xx[13] - (xx[11] * xx[11] + xx[10] * xx[10]) * xx[16]) * state[16]
    + xx[16] * xx[7] * xx[14] * state[17];
  xx[7] = xx[121] + xx[124];
  xx[125] = xx[16] * (xx[11] * xx[9] - xx[6] * xx[10]) * state[16] + (xx[13] -
    xx[16] * xx[14] * xx[14]) * state[17];
  xx[14] = xx[122] + xx[125];
  xx[121] = xx[123] + xx[16] * (xx[6] * xx[11] + xx[10] * xx[9]) * state[16] +
    state[18];
  pm_math_Vector3_cross_ra(xx + 115, xx + 60, xx + 126);
  xx[60] = xx[126] + xx[118];
  xx[61] = xx[127] + xx[119];
  xx[62] = xx[128] + xx[120];
  pm_math_Quaternion_inverseXform_ra(xx + 52, xx + 60, xx + 126);
  xx[52] = xx[126] - xx[125] * xx[12];
  xx[53] = xx[127] + xx[124] * xx[12];
  pm_math_Quaternion_inverseXform_ra(xx + 67, xx + 115, xx + 60);
  xx[54] = (xx[13] - (xx[28] * xx[28] + xx[27] * xx[27]) * xx[16]) * state[24] +
    xx[16] * xx[24] * xx[31] * state[25];
  xx[24] = xx[60] + xx[54];
  xx[55] = xx[16] * (xx[28] * xx[26] - xx[23] * xx[27]) * state[24] + (xx[13] -
    xx[16] * xx[31] * xx[31]) * state[25];
  xx[31] = xx[61] + xx[55];
  xx[60] = xx[62] + xx[16] * (xx[23] * xx[28] + xx[27] * xx[26]) * state[24] +
    state[26];
  pm_math_Vector3_cross_ra(xx + 115, xx + 75, xx + 122);
  xx[75] = xx[122] + xx[118];
  xx[76] = xx[123] + xx[119];
  xx[77] = xx[124] + xx[120];
  pm_math_Quaternion_inverseXform_ra(xx + 67, xx + 75, xx + 122);
  xx[61] = xx[122] - xx[55] * xx[12];
  xx[55] = xx[123] + xx[54] * xx[12];
  pm_math_Quaternion_inverseXform_ra(xx + 83, xx + 115, xx + 67);
  xx[54] = (xx[13] - (xx[38] * xx[38] + xx[37] * xx[37]) * xx[16]) * state[32] +
    xx[16] * xx[34] * xx[41] * state[33];
  xx[34] = xx[67] + xx[54];
  xx[62] = xx[16] * (xx[38] * xx[36] - xx[29] * xx[37]) * state[32] + (xx[13] -
    xx[16] * xx[41] * xx[41]) * state[33];
  xx[41] = xx[68] + xx[62];
  xx[67] = xx[69] + xx[16] * (xx[29] * xx[38] + xx[37] * xx[36]) * state[32] +
    state[34];
  pm_math_Vector3_cross_ra(xx + 115, xx + 91, xx + 68);
  xx[75] = xx[68] + xx[118];
  xx[76] = xx[69] + xx[119];
  xx[77] = xx[70] + xx[120];
  pm_math_Quaternion_inverseXform_ra(xx + 83, xx + 75, xx + 68);
  xx[75] = xx[68] - xx[62] * xx[12];
  xx[62] = xx[69] + xx[54] * xx[12];
  pm_math_Quaternion_inverseXform_ra(xx + 99, xx + 115, xx + 83);
  xx[54] = (xx[13] - (xx[48] * xx[48] + xx[47] * xx[47]) * xx[16]) * state[40] +
    xx[16] * xx[44] * xx[51] * state[41];
  xx[44] = xx[83] + xx[54];
  xx[68] = xx[16] * (xx[48] * xx[46] - xx[39] * xx[47]) * state[40] + (xx[13] -
    xx[16] * xx[51] * xx[51]) * state[41];
  xx[13] = xx[84] + xx[68];
  xx[51] = xx[85] + xx[16] * (xx[39] * xx[48] + xx[47] * xx[46]) * state[40] +
    state[42];
  pm_math_Vector3_cross_ra(xx + 115, xx + 107, xx + 83);
  xx[91] = xx[83] + xx[118];
  xx[92] = xx[84] + xx[119];
  xx[93] = xx[85] + xx[120];
  pm_math_Quaternion_inverseXform_ra(xx + 99, xx + 91, xx + 83);
  xx[69] = xx[83] - xx[68] * xx[12];
  xx[68] = xx[84] + xx[54] * xx[12];
  motionData[0] = xx[0];
  motionData[1] = xx[1];
  motionData[2] = xx[2];
  motionData[3] = xx[3];
  motionData[4] = state[0];
  motionData[5] = state[1];
  motionData[6] = xx[4];
  motionData[7] = xx[6];
  motionData[8] = xx[9];
  motionData[9] = xx[11];
  motionData[10] = xx[10];
  motionData[11] = xx[17];
  motionData[12] = xx[19];
  motionData[13] = xx[20];
  motionData[14] = xx[15];
  motionData[15] = xx[21];
  motionData[16] = xx[21];
  motionData[17] = xx[21];
  motionData[18] = xx[21];
  motionData[19] = xx[21];
  motionData[20] = xx[22];
  motionData[21] = xx[23];
  motionData[22] = xx[26];
  motionData[23] = xx[28];
  motionData[24] = xx[27];
  motionData[25] = xx[30];
  motionData[26] = xx[32];
  motionData[27] = xx[33];
  motionData[28] = xx[15];
  motionData[29] = xx[21];
  motionData[30] = xx[21];
  motionData[31] = xx[21];
  motionData[32] = xx[21];
  motionData[33] = xx[21];
  motionData[34] = xx[25];
  motionData[35] = xx[29];
  motionData[36] = xx[36];
  motionData[37] = xx[38];
  motionData[38] = xx[37];
  motionData[39] = xx[40];
  motionData[40] = xx[42];
  motionData[41] = xx[43];
  motionData[42] = xx[15];
  motionData[43] = xx[21];
  motionData[44] = xx[21];
  motionData[45] = xx[21];
  motionData[46] = xx[21];
  motionData[47] = xx[21];
  motionData[48] = xx[35];
  motionData[49] = xx[39];
  motionData[50] = xx[46];
  motionData[51] = xx[48];
  motionData[52] = xx[47];
  motionData[53] = xx[50];
  motionData[54] = xx[8];
  motionData[55] = xx[18];
  motionData[56] = xx[15];
  motionData[57] = xx[21];
  motionData[58] = xx[21];
  motionData[59] = xx[21];
  motionData[60] = xx[21];
  motionData[61] = xx[21];
  motionData[62] = xx[45];
  motionData[63] = cos(xx[49]);
  motionData[64] = xx[21];
  motionData[65] = sin(xx[49]);
  motionData[66] = xx[21];
  motionData[67] = xx[21];
  motionData[68] = xx[21];
  motionData[69] = xx[21];
  motionData[70] = xx[15];
  motionData[71] = xx[21];
  motionData[72] = xx[21];
  motionData[73] = xx[21];
  motionData[74] = state[47];
  motionData[75] = state[48];
  motionData[76] = state[49];
  motionData[77] = xx[56];
  motionData[78] = xx[57];
  motionData[79] = xx[58];
  motionData[80] = xx[59];
  motionData[81] = xx[5];
  motionData[82] = xx[66];
  motionData[83] = xx[63];
  motionData[84] = - xx[56];
  motionData[85] = - xx[57];
  motionData[86] = - xx[58];
  motionData[87] = - xx[59];
  motionData[88] = (xx[56] * xx[64] + xx[59] * xx[65]) * xx[16] + xx[5];
  motionData[89] = xx[16] * (xx[59] * xx[64] - xx[56] * xx[65]) + xx[66];
  motionData[90] = xx[22] - (xx[57] * xx[65] + xx[58] * xx[64]) * xx[16] + xx[63];
  motionData[91] = xx[71];
  motionData[92] = xx[72];
  motionData[93] = xx[73];
  motionData[94] = xx[74];
  motionData[95] = xx[81];
  motionData[96] = xx[82];
  motionData[97] = xx[78];
  motionData[98] = - xx[71];
  motionData[99] = - xx[72];
  motionData[100] = - xx[73];
  motionData[101] = - xx[74];
  motionData[102] = (xx[71] * xx[79] + xx[74] * xx[80]) * xx[16] + xx[81];
  motionData[103] = xx[16] * (xx[74] * xx[79] - xx[71] * xx[80]) + xx[82];
  motionData[104] = xx[25] - (xx[72] * xx[80] + xx[73] * xx[79]) * xx[16] + xx
    [78];
  motionData[105] = xx[87];
  motionData[106] = xx[88];
  motionData[107] = xx[89];
  motionData[108] = xx[90];
  motionData[109] = xx[97];
  motionData[110] = xx[98];
  motionData[111] = xx[94];
  motionData[112] = - xx[87];
  motionData[113] = - xx[88];
  motionData[114] = - xx[89];
  motionData[115] = - xx[90];
  motionData[116] = (xx[87] * xx[95] + xx[90] * xx[96]) * xx[16] + xx[97];
  motionData[117] = xx[16] * (xx[90] * xx[95] - xx[87] * xx[96]) + xx[98];
  motionData[118] = xx[35] - (xx[88] * xx[96] + xx[89] * xx[95]) * xx[16] + xx
    [94];
  motionData[119] = xx[103];
  motionData[120] = xx[104];
  motionData[121] = xx[105];
  motionData[122] = xx[106];
  motionData[123] = xx[113];
  motionData[124] = xx[114];
  motionData[125] = xx[110];
  motionData[126] = - xx[103];
  motionData[127] = - xx[104];
  motionData[128] = - xx[105];
  motionData[129] = - xx[106];
  motionData[130] = (xx[103] * xx[111] + xx[106] * xx[112]) * xx[16] + xx[113];
  motionData[131] = xx[16] * (xx[106] * xx[111] - xx[103] * xx[112]) + xx[114];
  motionData[132] = xx[45] - (xx[104] * xx[112] + xx[105] * xx[111]) * xx[16] +
    xx[110];
  motionData[133] = state[10];
  motionData[134] = state[11];
  motionData[135] = state[12];
  motionData[136] = xx[118];
  motionData[137] = xx[119];
  motionData[138] = xx[120];
  motionData[139] = xx[7];
  motionData[140] = xx[14];
  motionData[141] = xx[121];
  motionData[142] = xx[52];
  motionData[143] = xx[53];
  motionData[144] = xx[128];
  motionData[145] = xx[7];
  motionData[146] = xx[14];
  motionData[147] = xx[121];
  motionData[148] = xx[14] * xx[22] + xx[52];
  motionData[149] = xx[53] - xx[7] * xx[22];
  motionData[150] = xx[128] + state[20];
  motionData[151] = xx[24];
  motionData[152] = xx[31];
  motionData[153] = xx[60];
  motionData[154] = xx[61];
  motionData[155] = xx[55];
  motionData[156] = xx[124];
  motionData[157] = xx[24];
  motionData[158] = xx[31];
  motionData[159] = xx[60];
  motionData[160] = xx[31] * xx[25] + xx[61];
  motionData[161] = xx[55] - xx[24] * xx[25];
  motionData[162] = xx[124] + state[28];
  motionData[163] = xx[34];
  motionData[164] = xx[41];
  motionData[165] = xx[67];
  motionData[166] = xx[75];
  motionData[167] = xx[62];
  motionData[168] = xx[70];
  motionData[169] = xx[34];
  motionData[170] = xx[41];
  motionData[171] = xx[67];
  motionData[172] = xx[41] * xx[35] + xx[75];
  motionData[173] = xx[62] - xx[34] * xx[35];
  motionData[174] = xx[70] + state[36];
  motionData[175] = xx[44];
  motionData[176] = xx[13];
  motionData[177] = xx[51];
  motionData[178] = xx[69];
  motionData[179] = xx[68];
  motionData[180] = xx[85];
  motionData[181] = xx[44];
  motionData[182] = xx[13];
  motionData[183] = xx[51];
  motionData[184] = xx[13] * xx[45] + xx[69];
  motionData[185] = xx[68] - xx[44] * xx[45];
  motionData[186] = xx[85] + state[44];
  motionData[187] = xx[21];
  motionData[188] = state[46];
  motionData[189] = xx[21];
  motionData[190] = xx[21];
  motionData[191] = xx[21];
  motionData[192] = xx[21];
  motionData[193] = xx[21];
  motionData[194] = state[46];
  motionData[195] = xx[21];
  motionData[196] = state[46] * state[49] + state[50];
  motionData[197] = state[51];
  motionData[198] = state[52] - state[46] * state[47];
}

size_t robot_simple_balancing_f30145f9_1_computeAssemblyError(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const double
  *state, const int *modeVector, const double *motionData, double *error)
{
  (void) mech;
  (void)rtdv;
  (void) state;
  (void) modeVector;
  (void) motionData;
  (void) error;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t robot_simple_balancing_f30145f9_1_computeAssemblyJacobian(const void
  *mech, const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, boolean_T
  forVelocitySatisfaction, const double *state, const int *modeVector, const
  double *motionData, double *J)
{
  (void) mech;
  (void) rtdv;
  (void) state;
  (void) modeVector;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t robot_simple_balancing_f30145f9_1_computeFullAssemblyJacobian(const void *
  mech, const RuntimeDerivedValuesBundle *rtdv, const double *state, const int
  *modeVector, const double *motionData, double *J)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) motionData;
  (void) J;
  return 0;
}

int robot_simple_balancing_f30145f9_1_isInKinematicSingularity(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, size_t constraintIdx, const int
  *modeVector, const double *motionData)
{
  (void) mech;
  (void) rtdv
    ;
  (void) modeVector;
  (void) motionData;
  switch (constraintIdx)
  {
  }

  return 0;
}

PmfMessageId robot_simple_balancing_f30145f9_1_convertStateVector(const void
  *asmMech, const RuntimeDerivedValuesBundle *rtdv, const void *simMech, const
  double *asmState, const int *asmModeVector, const int *simModeVector, double
  *simState, void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) asmMech;
  (void) rtdvd;
  (void) rtdvi;
  (void) simMech;
  (void) asmModeVector;
  (void) simModeVector;
  (void) neDiagMgr;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  simState[4] = asmState[4];
  simState[5] = asmState[5];
  simState[6] = asmState[6];
  simState[7] = asmState[7];
  simState[8] = asmState[8];
  simState[9] = asmState[9];
  simState[10] = asmState[10];
  simState[11] = asmState[11];
  simState[12] = asmState[12];
  simState[13] = asmState[13];
  simState[14] = asmState[14];
  simState[15] = asmState[15];
  simState[16] = asmState[16];
  simState[17] = asmState[17];
  simState[18] = asmState[18];
  simState[19] = asmState[19];
  simState[20] = asmState[20];
  simState[21] = asmState[21];
  simState[22] = asmState[22];
  simState[23] = asmState[23];
  simState[24] = asmState[24];
  simState[25] = asmState[25];
  simState[26] = asmState[26];
  simState[27] = asmState[27];
  simState[28] = asmState[28];
  simState[29] = asmState[29];
  simState[30] = asmState[30];
  simState[31] = asmState[31];
  simState[32] = asmState[32];
  simState[33] = asmState[33];
  simState[34] = asmState[34];
  simState[35] = asmState[35];
  simState[36] = asmState[36];
  simState[37] = asmState[37];
  simState[38] = asmState[38];
  simState[39] = asmState[39];
  simState[40] = asmState[40];
  simState[41] = asmState[41];
  simState[42] = asmState[42];
  simState[43] = asmState[43];
  simState[44] = asmState[44];
  simState[45] = asmState[45];
  simState[46] = asmState[46];
  simState[47] = asmState[47];
  simState[48] = asmState[48];
  simState[49] = asmState[49];
  simState[50] = asmState[50];
  simState[51] = asmState[51];
  simState[52] = asmState[52];
  return NULL;
}
