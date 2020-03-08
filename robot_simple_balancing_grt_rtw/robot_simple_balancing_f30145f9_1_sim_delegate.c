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

void robot_simple_balancing_f30145f9_1_resetSimStateVector(const void *mech,
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

static void perturbSimJointPrimitiveState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbSimJointPrimitiveState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[7] = state[7] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_0_1(double mag, double *state)
{
  state[1] = state[1] + mag;
}

static void perturbSimJointPrimitiveState_0_1v(double mag, double *state)
{
  state[1] = state[1] + mag;
  state[8] = state[8] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_0_2(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbSimJointPrimitiveState_0_2v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[9] = state[9] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_0_3(double mag, double *state)
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

static void perturbSimJointPrimitiveState_0_3v(double mag, double *state)
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

static void perturbSimJointPrimitiveState_1_0(double mag, double *state)
{
  state[13] = state[13] + mag;
}

static void perturbSimJointPrimitiveState_1_0v(double mag, double *state)
{
  state[13] = state[13] + mag;
  state[16] = state[16] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_1_1(double mag, double *state)
{
  state[14] = state[14] + mag;
}

static void perturbSimJointPrimitiveState_1_1v(double mag, double *state)
{
  state[14] = state[14] + mag;
  state[17] = state[17] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_1_2(double mag, double *state)
{
  state[15] = state[15] + mag;
}

static void perturbSimJointPrimitiveState_1_2v(double mag, double *state)
{
  state[15] = state[15] + mag;
  state[18] = state[18] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_2_0(double mag, double *state)
{
  state[19] = state[19] + mag;
}

static void perturbSimJointPrimitiveState_2_0v(double mag, double *state)
{
  state[19] = state[19] + mag;
  state[20] = state[20] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_3_0(double mag, double *state)
{
  state[21] = state[21] + mag;
}

static void perturbSimJointPrimitiveState_3_0v(double mag, double *state)
{
  state[21] = state[21] + mag;
  state[24] = state[24] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_3_1(double mag, double *state)
{
  state[22] = state[22] + mag;
}

static void perturbSimJointPrimitiveState_3_1v(double mag, double *state)
{
  state[22] = state[22] + mag;
  state[25] = state[25] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_3_2(double mag, double *state)
{
  state[23] = state[23] + mag;
}

static void perturbSimJointPrimitiveState_3_2v(double mag, double *state)
{
  state[23] = state[23] + mag;
  state[26] = state[26] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_4_0(double mag, double *state)
{
  state[27] = state[27] + mag;
}

static void perturbSimJointPrimitiveState_4_0v(double mag, double *state)
{
  state[27] = state[27] + mag;
  state[28] = state[28] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_5_0(double mag, double *state)
{
  state[29] = state[29] + mag;
}

static void perturbSimJointPrimitiveState_5_0v(double mag, double *state)
{
  state[29] = state[29] + mag;
  state[32] = state[32] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_5_1(double mag, double *state)
{
  state[30] = state[30] + mag;
}

static void perturbSimJointPrimitiveState_5_1v(double mag, double *state)
{
  state[30] = state[30] + mag;
  state[33] = state[33] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_5_2(double mag, double *state)
{
  state[31] = state[31] + mag;
}

static void perturbSimJointPrimitiveState_5_2v(double mag, double *state)
{
  state[31] = state[31] + mag;
  state[34] = state[34] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_6_0(double mag, double *state)
{
  state[35] = state[35] + mag;
}

static void perturbSimJointPrimitiveState_6_0v(double mag, double *state)
{
  state[35] = state[35] + mag;
  state[36] = state[36] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_7_0(double mag, double *state)
{
  state[37] = state[37] + mag;
}

static void perturbSimJointPrimitiveState_7_0v(double mag, double *state)
{
  state[37] = state[37] + mag;
  state[40] = state[40] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_7_1(double mag, double *state)
{
  state[38] = state[38] + mag;
}

static void perturbSimJointPrimitiveState_7_1v(double mag, double *state)
{
  state[38] = state[38] + mag;
  state[41] = state[41] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_7_2(double mag, double *state)
{
  state[39] = state[39] + mag;
}

static void perturbSimJointPrimitiveState_7_2v(double mag, double *state)
{
  state[39] = state[39] + mag;
  state[42] = state[42] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_8_0(double mag, double *state)
{
  state[43] = state[43] + mag;
}

static void perturbSimJointPrimitiveState_8_0v(double mag, double *state)
{
  state[43] = state[43] + mag;
  state[44] = state[44] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_9_0(double mag, double *state)
{
  state[45] = state[45] + mag;
}

static void perturbSimJointPrimitiveState_9_0v(double mag, double *state)
{
  state[45] = state[45] + mag;
  state[46] = state[46] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_0(double mag, double *state)
{
  state[47] = state[47] + mag;
}

static void perturbSimJointPrimitiveState_10_0v(double mag, double *state)
{
  state[47] = state[47] + mag;
  state[50] = state[50] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_1(double mag, double *state)
{
  state[48] = state[48] + mag;
}

static void perturbSimJointPrimitiveState_10_1v(double mag, double *state)
{
  state[48] = state[48] + mag;
  state[51] = state[51] - 0.875 * mag;
}

static void perturbSimJointPrimitiveState_10_2(double mag, double *state)
{
  state[49] = state[49] + mag;
}

static void perturbSimJointPrimitiveState_10_2v(double mag, double *state)
{
  state[49] = state[49] + mag;
  state[52] = state[52] - 0.875 * mag;
}

void robot_simple_balancing_f30145f9_1_perturbSimJointPrimitiveState(const void *
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
    perturbSimJointPrimitiveState_0_0(mag, state);
    break;

   case 1:
    perturbSimJointPrimitiveState_0_0v(mag, state);
    break;

   case 2:
    perturbSimJointPrimitiveState_0_1(mag, state);
    break;

   case 3:
    perturbSimJointPrimitiveState_0_1v(mag, state);
    break;

   case 4:
    perturbSimJointPrimitiveState_0_2(mag, state);
    break;

   case 5:
    perturbSimJointPrimitiveState_0_2v(mag, state);
    break;

   case 6:
    perturbSimJointPrimitiveState_0_3(mag, state);
    break;

   case 7:
    perturbSimJointPrimitiveState_0_3v(mag, state);
    break;

   case 12:
    perturbSimJointPrimitiveState_1_0(mag, state);
    break;

   case 13:
    perturbSimJointPrimitiveState_1_0v(mag, state);
    break;

   case 14:
    perturbSimJointPrimitiveState_1_1(mag, state);
    break;

   case 15:
    perturbSimJointPrimitiveState_1_1v(mag, state);
    break;

   case 16:
    perturbSimJointPrimitiveState_1_2(mag, state);
    break;

   case 17:
    perturbSimJointPrimitiveState_1_2v(mag, state);
    break;

   case 24:
    perturbSimJointPrimitiveState_2_0(mag, state);
    break;

   case 25:
    perturbSimJointPrimitiveState_2_0v(mag, state);
    break;

   case 36:
    perturbSimJointPrimitiveState_3_0(mag, state);
    break;

   case 37:
    perturbSimJointPrimitiveState_3_0v(mag, state);
    break;

   case 38:
    perturbSimJointPrimitiveState_3_1(mag, state);
    break;

   case 39:
    perturbSimJointPrimitiveState_3_1v(mag, state);
    break;

   case 40:
    perturbSimJointPrimitiveState_3_2(mag, state);
    break;

   case 41:
    perturbSimJointPrimitiveState_3_2v(mag, state);
    break;

   case 48:
    perturbSimJointPrimitiveState_4_0(mag, state);
    break;

   case 49:
    perturbSimJointPrimitiveState_4_0v(mag, state);
    break;

   case 60:
    perturbSimJointPrimitiveState_5_0(mag, state);
    break;

   case 61:
    perturbSimJointPrimitiveState_5_0v(mag, state);
    break;

   case 62:
    perturbSimJointPrimitiveState_5_1(mag, state);
    break;

   case 63:
    perturbSimJointPrimitiveState_5_1v(mag, state);
    break;

   case 64:
    perturbSimJointPrimitiveState_5_2(mag, state);
    break;

   case 65:
    perturbSimJointPrimitiveState_5_2v(mag, state);
    break;

   case 72:
    perturbSimJointPrimitiveState_6_0(mag, state);
    break;

   case 73:
    perturbSimJointPrimitiveState_6_0v(mag, state);
    break;

   case 84:
    perturbSimJointPrimitiveState_7_0(mag, state);
    break;

   case 85:
    perturbSimJointPrimitiveState_7_0v(mag, state);
    break;

   case 86:
    perturbSimJointPrimitiveState_7_1(mag, state);
    break;

   case 87:
    perturbSimJointPrimitiveState_7_1v(mag, state);
    break;

   case 88:
    perturbSimJointPrimitiveState_7_2(mag, state);
    break;

   case 89:
    perturbSimJointPrimitiveState_7_2v(mag, state);
    break;

   case 96:
    perturbSimJointPrimitiveState_8_0(mag, state);
    break;

   case 97:
    perturbSimJointPrimitiveState_8_0v(mag, state);
    break;

   case 108:
    perturbSimJointPrimitiveState_9_0(mag, state);
    break;

   case 109:
    perturbSimJointPrimitiveState_9_0v(mag, state);
    break;

   case 120:
    perturbSimJointPrimitiveState_10_0(mag, state);
    break;

   case 121:
    perturbSimJointPrimitiveState_10_0v(mag, state);
    break;

   case 122:
    perturbSimJointPrimitiveState_10_1(mag, state);
    break;

   case 123:
    perturbSimJointPrimitiveState_10_1v(mag, state);
    break;

   case 124:
    perturbSimJointPrimitiveState_10_2(mag, state);
    break;

   case 125:
    perturbSimJointPrimitiveState_10_2v(mag, state);
    break;
  }
}

void robot_simple_balancing_f30145f9_1_perturbFlexibleBodyState(const void *mech,
  size_t stageIdx, double mag, boolean_T doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch (stageIdx * 2 + (doPerturbVelocity ? 1 : 0))
  {
  }
}

void robot_simple_balancing_f30145f9_1_constructStateVector(const void *mech,
  const double *solverState, const double *u, const double *uDot, double
  *discreteState, double *fullState)
{
  (void) mech;
  (void) discreteState;
  fullState[0] = solverState[0];
  fullState[1] = solverState[1];
  fullState[2] = solverState[2];
  fullState[3] = solverState[3];
  fullState[4] = solverState[4];
  fullState[5] = solverState[5];
  fullState[6] = solverState[6];
  fullState[7] = solverState[7];
  fullState[8] = solverState[8];
  fullState[9] = solverState[9];
  fullState[10] = solverState[10];
  fullState[11] = solverState[11];
  fullState[12] = solverState[12];
  fullState[13] = u[4];
  fullState[14] = u[5];
  fullState[15] = u[6];
  fullState[16] = uDot[4];
  fullState[17] = uDot[5];
  fullState[18] = uDot[6];
  fullState[19] = u[7];
  fullState[20] = uDot[7];
  fullState[21] = u[8];
  fullState[22] = u[9];
  fullState[23] = u[10];
  fullState[24] = uDot[8];
  fullState[25] = uDot[9];
  fullState[26] = uDot[10];
  fullState[27] = u[11];
  fullState[28] = uDot[11];
  fullState[29] = u[12];
  fullState[30] = u[13];
  fullState[31] = u[14];
  fullState[32] = uDot[12];
  fullState[33] = uDot[13];
  fullState[34] = uDot[14];
  fullState[35] = u[15];
  fullState[36] = uDot[15];
  fullState[37] = u[16];
  fullState[38] = u[17];
  fullState[39] = u[18];
  fullState[40] = uDot[16];
  fullState[41] = uDot[17];
  fullState[42] = uDot[18];
  fullState[43] = u[19];
  fullState[44] = uDot[19];
  fullState[45] = u[3];
  fullState[46] = uDot[3];
  fullState[47] = u[0];
  fullState[48] = u[1];
  fullState[49] = u[2];
  fullState[50] = uDot[0];
  fullState[51] = uDot[1];
  fullState[52] = uDot[2];
}

void robot_simple_balancing_f30145f9_1_extractSolverStateVector(const void *mech,
  const double *fullState, double *solverState)
{
  (void) mech;
  solverState[0] = fullState[0];
  solverState[1] = fullState[1];
  solverState[2] = fullState[2];
  solverState[3] = fullState[3];
  solverState[4] = fullState[4];
  solverState[5] = fullState[5];
  solverState[6] = fullState[6];
  solverState[7] = fullState[7];
  solverState[8] = fullState[8];
  solverState[9] = fullState[9];
  solverState[10] = fullState[10];
  solverState[11] = fullState[11];
  solverState[12] = fullState[12];
}

int robot_simple_balancing_f30145f9_1_isPositionViolation(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const
  double *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  return 0;
}

int robot_simple_balancing_f30145f9_1_isVelocityViolation(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const
  double *state, const int *modeVector)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) state;
  (void) modeVector;
  return 0;
}

PmfMessageId robot_simple_balancing_f30145f9_1_projectStateSim(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const int
  *modeVector, const double *input, double *state, void *neDiagMgr0)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  double xx[1];
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) input;
  (void) neDiagMgr;
  xx[0] = 1.0 / sqrt(state[3] * state[3] + state[4] * state[4] + state[5] *
                     state[5] + state[6] * state[6]);
  state[3] = xx[0] * state[3];
  state[4] = xx[0] * state[4];
  state[5] = xx[0] * state[5];
  state[6] = xx[0] * state[6];
  return NULL;
}

void robot_simple_balancing_f30145f9_1_computeConstraintError(const void *mech,
  const RuntimeDerivedValuesBundle *rtdv, const double *state, const int
  *modeVector, double *error)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  (void) mech;
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) modeVector;
  (void) error;
}

void robot_simple_balancing_f30145f9_1_resetModeVector(const void *mech, int
  *modeVector)
{
  (void) mech;
  (void) modeVector;
}
