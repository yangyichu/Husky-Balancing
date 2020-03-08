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
#include "robot_simple_balancing_f30145f9_1_geometries.h"

PmfMessageId robot_simple_balancing_f30145f9_1_checkDynamics(const
  RuntimeDerivedValuesBundle *rtdv, const double *state, const double *input,
  const double *inputDot, const double *inputDdot, const double *discreteState,
  double *result, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  double xx[6];
  (void) rtdvd;
  (void) rtdvi;
  (void) state;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = input[29] + input[41] + input[53] + input[65] + input[23] + input[35]
    + input[47] + input[59];
  xx[1] = input[30] + input[42] + input[54] + input[66] + input[24] + input[36]
    + input[48] + input[60];
  xx[2] = input[31] + input[43] + input[55] + input[67] + input[25] + input[37]
    + input[49] + input[61];
  xx[3] = input[26] + input[38] + input[50] + input[62] + input[20] + input[32]
    + input[44] + input[56];
  xx[4] = input[27] + input[39] + input[51] + input[63] + input[21] + input[33]
    + input[45] + input[57];
  xx[5] = input[28] + input[40] + input[52] + input[64] + input[22] + input[34]
    + input[46] + input[58];
  result[0] = xx[0] * xx[0] + xx[1] * xx[1] + xx[2] * xx[2] + xx[3] * xx[3] +
    xx[4] * xx[4] + xx[5] * xx[5];
  return NULL;
}
