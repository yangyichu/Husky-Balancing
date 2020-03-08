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

PmfMessageId robot_simple_balancing_f30145f9_1_deriv(const
  RuntimeDerivedValuesBundle *rtdv, const int *eqnEnableFlags, const double
  *state, const int *modeVector, const double *input, const double *inputDot,
  const double *inputDdot, const double *discreteState, double *deriv, double
  *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  const double *rtdvd = rtdv->mDoubles.mValues;
  const int *rtdvi = rtdv->mInts.mValues;
  int ii[4];
  double xx[389];
  (void) rtdvd;
  (void) rtdvi;
  (void) eqnEnableFlags;
  (void) modeVector;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = state[3];
  xx[1] = state[4];
  xx[2] = state[5];
  xx[3] = state[6];
  xx[4] = state[10];
  xx[5] = state[11];
  xx[6] = state[12];
  pm_math_Quaternion_compDeriv_ra(xx + 0, xx + 4, xx + 7);
  xx[0] = 1.0;
  xx[1] = state[5] * state[5];
  xx[2] = state[6] * state[6];
  xx[3] = 2.0;
  xx[11] = state[4] * state[5];
  xx[12] = state[3] * state[6];
  xx[13] = state[3] * state[5];
  xx[14] = state[4] * state[6];
  xx[15] = xx[0] - (xx[1] + xx[2]) * xx[3];
  xx[16] = xx[3] * (xx[11] - xx[12]);
  xx[17] = (xx[13] + xx[14]) * xx[3];
  xx[18] = 0.5;
  xx[19] = xx[18] * input[18];
  xx[20] = cos(xx[19]);
  xx[21] = xx[18] * input[17];
  xx[22] = cos(xx[21]);
  xx[23] = xx[18] * input[16];
  xx[24] = sin(xx[23]);
  xx[25] = xx[22] * xx[24];
  xx[26] = cos(xx[23]);
  xx[23] = sin(xx[21]);
  xx[21] = xx[26] * xx[23];
  xx[27] = sin(xx[19]);
  xx[19] = xx[20] * xx[25] + xx[21] * xx[27];
  xx[28] = xx[19] * xx[19];
  xx[29] = xx[24] * xx[23];
  xx[23] = xx[26] * xx[22];
  xx[22] = xx[29] * xx[27] - xx[20] * xx[23];
  xx[24] = (xx[28] + xx[22] * xx[22]) * xx[3] - xx[0];
  xx[26] = xx[20] * xx[29] + xx[23] * xx[27];
  xx[23] = xx[26] * xx[22];
  xx[29] = xx[25] * xx[27] - xx[20] * xx[21];
  xx[21] = xx[19] * xx[29];
  xx[25] = xx[3] * (xx[23] - xx[21]);
  xx[30] = xx[29] * xx[22];
  xx[31] = xx[19] * xx[26];
  xx[32] = (xx[30] + xx[31]) * xx[3];
  xx[33] = (xx[23] + xx[21]) * xx[3];
  xx[21] = xx[26] * xx[26];
  xx[23] = (xx[28] + xx[21]) * xx[3] - xx[0];
  xx[34] = xx[26] * xx[29];
  xx[35] = xx[19] * xx[22];
  xx[36] = xx[3] * (xx[34] - xx[35]);
  xx[37] = xx[3] * (xx[30] - xx[31]);
  xx[38] = (xx[34] + xx[35]) * xx[3];
  xx[34] = xx[29] * xx[29];
  xx[35] = (xx[28] + xx[34]) * xx[3] - xx[0];
  xx[39] = xx[24];
  xx[40] = xx[25];
  xx[41] = xx[32];
  xx[42] = xx[33];
  xx[43] = xx[23];
  xx[44] = xx[36];
  xx[45] = xx[37];
  xx[46] = xx[38];
  xx[47] = xx[35];
  xx[28] = 0.1266637061435917;
  xx[48] = xx[28] * xx[24];
  xx[49] = xx[28] * xx[33];
  xx[50] = xx[28] * xx[37];
  xx[51] = xx[28] * xx[25];
  xx[52] = xx[28] * xx[23];
  xx[53] = xx[28] * xx[38];
  xx[54] = xx[28] * xx[32];
  xx[55] = xx[28] * xx[36];
  xx[56] = xx[28] * xx[35];
  pm_math_Matrix3x3_compose_ra(xx + 39, xx + 48, xx + 57);
  xx[48] = xx[18] * input[14];
  xx[49] = cos(xx[48]);
  xx[50] = xx[18] * input[13];
  xx[51] = cos(xx[50]);
  xx[52] = xx[18] * input[12];
  xx[53] = sin(xx[52]);
  xx[54] = xx[51] * xx[53];
  xx[55] = cos(xx[52]);
  xx[52] = sin(xx[50]);
  xx[50] = xx[55] * xx[52];
  xx[56] = sin(xx[48]);
  xx[48] = xx[49] * xx[54] + xx[50] * xx[56];
  xx[66] = xx[48] * xx[48];
  xx[67] = xx[53] * xx[52];
  xx[52] = xx[55] * xx[51];
  xx[51] = xx[67] * xx[56] - xx[49] * xx[52];
  xx[53] = (xx[66] + xx[51] * xx[51]) * xx[3] - xx[0];
  xx[55] = xx[49] * xx[67] + xx[52] * xx[56];
  xx[52] = xx[55] * xx[51];
  xx[67] = xx[54] * xx[56] - xx[49] * xx[50];
  xx[50] = xx[48] * xx[67];
  xx[54] = xx[3] * (xx[52] - xx[50]);
  xx[68] = xx[67] * xx[51];
  xx[69] = xx[48] * xx[55];
  xx[70] = (xx[68] + xx[69]) * xx[3];
  xx[71] = (xx[52] + xx[50]) * xx[3];
  xx[50] = xx[55] * xx[55];
  xx[52] = (xx[66] + xx[50]) * xx[3] - xx[0];
  xx[72] = xx[55] * xx[67];
  xx[73] = xx[48] * xx[51];
  xx[74] = xx[3] * (xx[72] - xx[73]);
  xx[75] = xx[3] * (xx[68] - xx[69]);
  xx[76] = (xx[72] + xx[73]) * xx[3];
  xx[72] = xx[67] * xx[67];
  xx[73] = (xx[66] + xx[72]) * xx[3] - xx[0];
  xx[77] = xx[53];
  xx[78] = xx[54];
  xx[79] = xx[70];
  xx[80] = xx[71];
  xx[81] = xx[52];
  xx[82] = xx[74];
  xx[83] = xx[75];
  xx[84] = xx[76];
  xx[85] = xx[73];
  xx[86] = xx[28] * xx[53];
  xx[87] = xx[28] * xx[71];
  xx[88] = xx[28] * xx[75];
  xx[89] = xx[28] * xx[54];
  xx[90] = xx[28] * xx[52];
  xx[91] = xx[28] * xx[76];
  xx[92] = xx[28] * xx[70];
  xx[93] = xx[28] * xx[74];
  xx[94] = xx[28] * xx[73];
  pm_math_Matrix3x3_compose_ra(xx + 77, xx + 86, xx + 95);
  xx[66] = xx[18] * input[10];
  xx[86] = cos(xx[66]);
  xx[87] = xx[18] * input[9];
  xx[88] = cos(xx[87]);
  xx[89] = xx[18] * input[8];
  xx[90] = sin(xx[89]);
  xx[91] = xx[88] * xx[90];
  xx[92] = cos(xx[89]);
  xx[89] = sin(xx[87]);
  xx[87] = xx[92] * xx[89];
  xx[93] = sin(xx[66]);
  xx[66] = xx[86] * xx[91] + xx[87] * xx[93];
  xx[94] = xx[66] * xx[66];
  xx[104] = xx[90] * xx[89];
  xx[89] = xx[92] * xx[88];
  xx[88] = xx[104] * xx[93] - xx[86] * xx[89];
  xx[90] = (xx[94] + xx[88] * xx[88]) * xx[3] - xx[0];
  xx[92] = xx[86] * xx[104] + xx[89] * xx[93];
  xx[89] = xx[92] * xx[88];
  xx[104] = xx[91] * xx[93] - xx[86] * xx[87];
  xx[87] = xx[66] * xx[104];
  xx[91] = xx[3] * (xx[89] - xx[87]);
  xx[105] = xx[104] * xx[88];
  xx[106] = xx[66] * xx[92];
  xx[107] = (xx[105] + xx[106]) * xx[3];
  xx[108] = (xx[89] + xx[87]) * xx[3];
  xx[87] = xx[92] * xx[92];
  xx[89] = (xx[94] + xx[87]) * xx[3] - xx[0];
  xx[109] = xx[92] * xx[104];
  xx[110] = xx[66] * xx[88];
  xx[111] = xx[3] * (xx[109] - xx[110]);
  xx[112] = xx[3] * (xx[105] - xx[106]);
  xx[113] = (xx[109] + xx[110]) * xx[3];
  xx[109] = xx[104] * xx[104];
  xx[110] = (xx[94] + xx[109]) * xx[3] - xx[0];
  xx[114] = xx[90];
  xx[115] = xx[91];
  xx[116] = xx[107];
  xx[117] = xx[108];
  xx[118] = xx[89];
  xx[119] = xx[111];
  xx[120] = xx[112];
  xx[121] = xx[113];
  xx[122] = xx[110];
  xx[123] = xx[28] * xx[90];
  xx[124] = xx[28] * xx[108];
  xx[125] = xx[28] * xx[112];
  xx[126] = xx[28] * xx[91];
  xx[127] = xx[28] * xx[89];
  xx[128] = xx[28] * xx[113];
  xx[129] = xx[28] * xx[107];
  xx[130] = xx[28] * xx[111];
  xx[131] = xx[28] * xx[110];
  pm_math_Matrix3x3_compose_ra(xx + 114, xx + 123, xx + 132);
  xx[94] = 10.0;
  xx[123] = xx[18] * input[6];
  xx[124] = cos(xx[123]);
  xx[125] = xx[18] * input[5];
  xx[126] = cos(xx[125]);
  xx[127] = xx[18] * input[4];
  xx[18] = sin(xx[127]);
  xx[128] = xx[126] * xx[18];
  xx[129] = cos(xx[127]);
  xx[127] = sin(xx[125]);
  xx[125] = xx[129] * xx[127];
  xx[130] = sin(xx[123]);
  xx[123] = xx[124] * xx[128] + xx[125] * xx[130];
  xx[131] = xx[123] * xx[123];
  xx[141] = xx[18] * xx[127];
  xx[18] = xx[129] * xx[126];
  xx[126] = xx[141] * xx[130] - xx[124] * xx[18];
  xx[127] = (xx[131] + xx[126] * xx[126]) * xx[3] - xx[0];
  xx[129] = xx[124] * xx[141] + xx[18] * xx[130];
  xx[18] = xx[129] * xx[126];
  xx[141] = xx[128] * xx[130] - xx[124] * xx[125];
  xx[125] = xx[123] * xx[141];
  xx[128] = xx[3] * (xx[18] - xx[125]);
  xx[142] = xx[141] * xx[126];
  xx[143] = xx[123] * xx[129];
  xx[144] = (xx[142] + xx[143]) * xx[3];
  xx[145] = (xx[18] + xx[125]) * xx[3];
  xx[18] = xx[129] * xx[129];
  xx[125] = (xx[131] + xx[18]) * xx[3] - xx[0];
  xx[146] = xx[129] * xx[141];
  xx[147] = xx[123] * xx[126];
  xx[148] = xx[3] * (xx[146] - xx[147]);
  xx[149] = xx[3] * (xx[142] - xx[143]);
  xx[150] = (xx[146] + xx[147]) * xx[3];
  xx[146] = xx[141] * xx[141];
  xx[147] = (xx[131] + xx[146]) * xx[3] - xx[0];
  xx[151] = xx[127];
  xx[152] = xx[128];
  xx[153] = xx[144];
  xx[154] = xx[145];
  xx[155] = xx[125];
  xx[156] = xx[148];
  xx[157] = xx[149];
  xx[158] = xx[150];
  xx[159] = xx[147];
  xx[160] = xx[28] * xx[127];
  xx[161] = xx[28] * xx[145];
  xx[162] = xx[28] * xx[149];
  xx[163] = xx[28] * xx[128];
  xx[164] = xx[28] * xx[125];
  xx[165] = xx[28] * xx[150];
  xx[166] = xx[28] * xx[144];
  xx[167] = xx[28] * xx[148];
  xx[168] = xx[28] * xx[147];
  pm_math_Matrix3x3_compose_ra(xx + 151, xx + 160, xx + 169);
  xx[160] = xx[57] + xx[95] + xx[132] + xx[94] + xx[169];
  xx[161] = xx[58] + xx[96] + xx[133] + xx[170];
  xx[162] = xx[59] + xx[97] + xx[134] + xx[171];
  xx[163] = xx[60] + xx[98] + xx[135] + xx[172];
  xx[164] = xx[61] + xx[99] + xx[136] + xx[94] + xx[173];
  xx[165] = xx[62] + xx[100] + xx[137] + xx[174];
  xx[166] = xx[63] + xx[101] + xx[138] + xx[175];
  xx[167] = xx[64] + xx[102] + xx[139] + xx[176];
  xx[168] = xx[65] + xx[103] + xx[140] + xx[94] + xx[177];
  pm_math_Matrix3x3_xform_ra(xx + 160, xx + 15, xx + 178);
  xx[94] = state[4] * state[4];
  xx[131] = state[5] * state[6];
  xx[181] = state[3] * state[4];
  xx[182] = (xx[12] + xx[11]) * xx[3];
  xx[183] = xx[0] - (xx[2] + xx[94]) * xx[3];
  xx[184] = xx[3] * (xx[131] - xx[181]);
  pm_math_Matrix3x3_xform_ra(xx + 160, xx + 182, xx + 185);
  xx[2] = pm_math_Vector3_dot_ra(xx + 15, xx + 185);
  xx[188] = xx[3] * (xx[14] - xx[13]);
  xx[189] = (xx[181] + xx[131]) * xx[3];
  xx[190] = xx[0] - (xx[94] + xx[1]) * xx[3];
  pm_math_Matrix3x3_xform_ra(xx + 160, xx + 188, xx + 11);
  xx[1] = pm_math_Vector3_dot_ra(xx + 15, xx + 11);
  xx[14] = 0.05;
  xx[94] = input[19] - xx[14];
  xx[131] = 1.0e-3;
  xx[181] = xx[94] * xx[131];
  xx[191] = xx[181] * xx[24];
  xx[192] = xx[181] * xx[25];
  xx[193] = xx[25] * xx[191] - xx[192] * xx[24];
  xx[194] = 0.3;
  xx[195] = xx[26] * xx[14];
  xx[196] = xx[14] * xx[22];
  xx[197] = 0.2;
  xx[198] = - (xx[194] + (xx[19] * xx[195] + xx[196] * xx[29]) * xx[3]);
  xx[199] = xx[197] - xx[3] * (xx[195] * xx[29] - xx[19] * xx[196]);
  xx[200] = - (xx[14] - (xx[196] * xx[22] + xx[26] * xx[195]) * xx[3]);
  pm_math_Matrix3x3_postCross_ra(xx + 57, xx + 198, xx + 201);
  xx[57] = input[15] - xx[14];
  xx[58] = xx[57] * xx[131];
  xx[59] = xx[58] * xx[53];
  xx[60] = xx[58] * xx[54];
  xx[61] = xx[54] * xx[59] - xx[60] * xx[53];
  xx[62] = xx[55] * xx[14];
  xx[63] = xx[14] * xx[51];
  xx[210] = - (xx[194] + (xx[48] * xx[62] + xx[63] * xx[67]) * xx[3]);
  xx[211] = - (xx[197] + xx[3] * (xx[62] * xx[67] - xx[48] * xx[63]));
  xx[212] = - (xx[14] - (xx[63] * xx[51] + xx[55] * xx[62]) * xx[3]);
  pm_math_Matrix3x3_postCross_ra(xx + 95, xx + 210, xx + 213);
  xx[62] = input[11] - xx[14];
  xx[63] = xx[62] * xx[131];
  xx[64] = xx[63] * xx[90];
  xx[65] = xx[63] * xx[91];
  xx[95] = xx[91] * xx[64] - xx[65] * xx[90];
  xx[96] = xx[92] * xx[14];
  xx[97] = xx[14] * xx[88];
  xx[98] = xx[194] - (xx[66] * xx[96] + xx[97] * xx[104]) * xx[3];
  xx[99] = xx[197] - xx[3] * (xx[96] * xx[104] - xx[66] * xx[97]);
  xx[100] = - (xx[14] - (xx[97] * xx[88] + xx[92] * xx[96]) * xx[3]);
  pm_math_Matrix3x3_postCross_ra(xx + 132, xx + 98, xx + 222);
  xx[96] = input[7] - xx[14];
  xx[97] = xx[96] * xx[131];
  xx[101] = xx[97] * xx[127];
  xx[102] = xx[97] * xx[128];
  xx[103] = xx[128] * xx[101] - xx[102] * xx[127];
  xx[132] = xx[129] * xx[14];
  xx[133] = xx[14] * xx[126];
  xx[134] = xx[194] - (xx[123] * xx[132] + xx[133] * xx[141]) * xx[3];
  xx[135] = - (xx[197] + xx[3] * (xx[132] * xx[141] - xx[123] * xx[133]));
  xx[136] = - (xx[14] - (xx[133] * xx[126] + xx[129] * xx[132]) * xx[3]);
  pm_math_Matrix3x3_postCross_ra(xx + 169, xx + 134, xx + 231);
  xx[132] = xx[193] - xx[201] + xx[61] - xx[213] + xx[95] - xx[222] + xx[103] -
    xx[231];
  xx[133] = xx[33] * xx[181];
  xx[137] = xx[181] * xx[23];
  xx[138] = xx[25] * xx[133] - xx[137] * xx[24];
  xx[139] = xx[71] * xx[58];
  xx[140] = xx[58] * xx[52];
  xx[169] = xx[54] * xx[139] - xx[140] * xx[53];
  xx[170] = xx[108] * xx[63];
  xx[171] = xx[63] * xx[89];
  xx[172] = xx[91] * xx[170] - xx[171] * xx[90];
  xx[173] = xx[145] * xx[97];
  xx[174] = xx[97] * xx[125];
  xx[175] = xx[128] * xx[173] - xx[174] * xx[127];
  xx[176] = xx[138] - xx[204] + xx[169] - xx[216] + xx[172] - xx[225] + xx[175]
    - xx[234];
  xx[177] = xx[181] * xx[37];
  xx[194] = xx[38] * xx[181];
  xx[195] = xx[25] * xx[177] - xx[194] * xx[24];
  xx[196] = xx[58] * xx[75];
  xx[197] = xx[76] * xx[58];
  xx[240] = xx[54] * xx[196] - xx[197] * xx[53];
  xx[241] = xx[63] * xx[112];
  xx[242] = xx[113] * xx[63];
  xx[243] = xx[91] * xx[241] - xx[242] * xx[90];
  xx[244] = xx[97] * xx[149];
  xx[245] = xx[150] * xx[97];
  xx[246] = xx[128] * xx[244] - xx[245] * xx[127];
  xx[247] = xx[195] - xx[207] + xx[240] - xx[219] + xx[243] - xx[228] + xx[246]
    - xx[237];
  xx[248] = xx[132];
  xx[249] = xx[176];
  xx[250] = xx[247];
  xx[251] = pm_math_Vector3_dot_ra(xx + 15, xx + 248);
  xx[252] = xx[191] * xx[23] - xx[33] * xx[192];
  xx[253] = xx[59] * xx[52] - xx[71] * xx[60];
  xx[254] = xx[64] * xx[89] - xx[108] * xx[65];
  xx[255] = xx[101] * xx[125] - xx[145] * xx[102];
  xx[256] = xx[252] - xx[202] + xx[253] - xx[214] + xx[254] - xx[223] + xx[255]
    - xx[232];
  xx[257] = xx[133] * xx[23] - xx[33] * xx[137];
  xx[258] = xx[139] * xx[52] - xx[71] * xx[140];
  xx[259] = xx[170] * xx[89] - xx[108] * xx[171];
  xx[260] = xx[173] * xx[125] - xx[145] * xx[174];
  xx[261] = xx[257] - xx[205] + xx[258] - xx[217] + xx[259] - xx[226] + xx[260]
    - xx[235];
  xx[262] = xx[177] * xx[23] - xx[33] * xx[194];
  xx[263] = xx[196] * xx[52] - xx[71] * xx[197];
  xx[264] = xx[241] * xx[89] - xx[108] * xx[242];
  xx[265] = xx[244] * xx[125] - xx[145] * xx[245];
  xx[266] = xx[262] - xx[208] + xx[263] - xx[220] + xx[264] - xx[229] + xx[265]
    - xx[238];
  xx[267] = xx[256];
  xx[268] = xx[261];
  xx[269] = xx[266];
  xx[270] = pm_math_Vector3_dot_ra(xx + 15, xx + 267);
  xx[271] = xx[38] * xx[191] - xx[37] * xx[192];
  xx[191] = xx[76] * xx[59] - xx[75] * xx[60];
  xx[59] = xx[113] * xx[64] - xx[112] * xx[65];
  xx[60] = xx[150] * xx[101] - xx[149] * xx[102];
  xx[64] = xx[271] - xx[203] + xx[191] - xx[215] + xx[59] - xx[224] + xx[60] -
    xx[233];
  xx[65] = xx[38] * xx[133] - xx[37] * xx[137];
  xx[101] = xx[76] * xx[139] - xx[75] * xx[140];
  xx[102] = xx[113] * xx[170] - xx[112] * xx[171];
  xx[133] = xx[150] * xx[173] - xx[149] * xx[174];
  xx[137] = xx[65] - xx[206] + xx[101] - xx[218] + xx[102] - xx[227] + xx[133] -
    xx[236];
  xx[139] = xx[38] * xx[177] - xx[37] * xx[194];
  xx[140] = xx[76] * xx[196] - xx[75] * xx[197];
  xx[170] = xx[113] * xx[241] - xx[112] * xx[242];
  xx[171] = xx[150] * xx[244] - xx[149] * xx[245];
  xx[173] = xx[139] - xx[209] + xx[140] - xx[221] + xx[170] - xx[230] + xx[171]
    - xx[239];
  xx[272] = xx[64];
  xx[273] = xx[137];
  xx[274] = xx[173];
  xx[174] = pm_math_Vector3_dot_ra(xx + 15, xx + 272);
  xx[177] = pm_math_Vector3_dot_ra(xx + 182, xx + 11);
  xx[192] = pm_math_Vector3_dot_ra(xx + 182, xx + 248);
  xx[194] = pm_math_Vector3_dot_ra(xx + 182, xx + 267);
  xx[196] = pm_math_Vector3_dot_ra(xx + 182, xx + 272);
  xx[197] = pm_math_Vector3_dot_ra(xx + 188, xx + 248);
  xx[241] = pm_math_Vector3_dot_ra(xx + 188, xx + 267);
  xx[242] = pm_math_Vector3_dot_ra(xx + 188, xx + 272);
  xx[244] = 1.17286125734019e-4;
  xx[245] = xx[244] + xx[94] * xx[181];
  xx[248] = 2.513274122871835e-5;
  xx[272] = xx[245] * xx[24];
  xx[273] = xx[245] * xx[33];
  xx[274] = xx[245] * xx[37];
  xx[275] = xx[245] * xx[25];
  xx[276] = xx[245] * xx[23];
  xx[277] = xx[245] * xx[38];
  xx[278] = xx[248] * xx[32];
  xx[279] = xx[248] * xx[36];
  xx[280] = xx[248] * xx[35];
  pm_math_Matrix3x3_compose_ra(xx + 39, xx + 272, xx + 281);
  xx[35] = xx[193];
  xx[36] = xx[138];
  xx[37] = xx[195];
  xx[38] = xx[252];
  xx[39] = xx[257];
  xx[40] = xx[262];
  xx[41] = xx[271];
  xx[42] = xx[65];
  xx[43] = xx[139];
  pm_math_Matrix3x3_postCross_ra(xx + 35, xx + 198, xx + 271);
  pm_math_Matrix3x3_preCross_ra(xx + 201, xx + 198, xx + 35);
  xx[23] = xx[244] + xx[57] * xx[58];
  xx[201] = xx[23] * xx[53];
  xx[202] = xx[23] * xx[71];
  xx[203] = xx[23] * xx[75];
  xx[204] = xx[23] * xx[54];
  xx[205] = xx[23] * xx[52];
  xx[206] = xx[23] * xx[76];
  xx[207] = xx[248] * xx[70];
  xx[208] = xx[248] * xx[74];
  xx[209] = xx[248] * xx[73];
  pm_math_Matrix3x3_compose_ra(xx + 77, xx + 201, xx + 290);
  xx[73] = xx[61];
  xx[74] = xx[169];
  xx[75] = xx[240];
  xx[76] = xx[253];
  xx[77] = xx[258];
  xx[78] = xx[263];
  xx[79] = xx[191];
  xx[80] = xx[101];
  xx[81] = xx[140];
  pm_math_Matrix3x3_postCross_ra(xx + 73, xx + 210, xx + 201);
  pm_math_Matrix3x3_preCross_ra(xx + 213, xx + 210, xx + 73);
  xx[24] = xx[244] + xx[62] * xx[63];
  xx[213] = xx[24] * xx[90];
  xx[214] = xx[24] * xx[108];
  xx[215] = xx[24] * xx[112];
  xx[216] = xx[24] * xx[91];
  xx[217] = xx[24] * xx[89];
  xx[218] = xx[24] * xx[113];
  xx[219] = xx[248] * xx[107];
  xx[220] = xx[248] * xx[111];
  xx[221] = xx[248] * xx[110];
  pm_math_Matrix3x3_compose_ra(xx + 114, xx + 213, xx + 299);
  xx[110] = xx[95];
  xx[111] = xx[172];
  xx[112] = xx[243];
  xx[113] = xx[254];
  xx[114] = xx[259];
  xx[115] = xx[264];
  xx[116] = xx[59];
  xx[117] = xx[102];
  xx[118] = xx[170];
  pm_math_Matrix3x3_postCross_ra(xx + 110, xx + 98, xx + 213);
  pm_math_Matrix3x3_preCross_ra(xx + 222, xx + 98, xx + 110);
  xx[32] = 0.1666666666666667;
  xx[33] = xx[244] + xx[96] * xx[97];
  xx[222] = xx[33] * xx[127];
  xx[223] = xx[33] * xx[145];
  xx[224] = xx[33] * xx[149];
  xx[225] = xx[33] * xx[128];
  xx[226] = xx[33] * xx[125];
  xx[227] = xx[33] * xx[150];
  xx[228] = xx[248] * xx[144];
  xx[229] = xx[248] * xx[148];
  xx[230] = xx[248] * xx[147];
  pm_math_Matrix3x3_compose_ra(xx + 151, xx + 222, xx + 308);
  xx[147] = xx[103];
  xx[148] = xx[175];
  xx[149] = xx[246];
  xx[150] = xx[255];
  xx[151] = xx[260];
  xx[152] = xx[265];
  xx[153] = xx[60];
  xx[154] = xx[133];
  xx[155] = xx[171];
  pm_math_Matrix3x3_postCross_ra(xx + 147, xx + 134, xx + 222);
  pm_math_Matrix3x3_preCross_ra(xx + 231, xx + 134, xx + 147);
  xx[44] = xx[281] - xx[271] - xx[271] - xx[35] + xx[290] - xx[201] - xx[201] -
    xx[73] + xx[299] - xx[213] - xx[213] - xx[110] + xx[32] + xx[308] - xx[222]
    - xx[222] - xx[147];
  xx[45] = xx[282] - xx[272] - xx[274] - xx[36] + xx[291] - xx[202] - xx[204] -
    xx[74] + xx[300] - xx[214] - xx[216] - xx[111] + xx[309] - xx[223] - xx[225]
    - xx[148];
  xx[46] = xx[283] - xx[273] - xx[277] - xx[37] + xx[292] - xx[203] - xx[207] -
    xx[75] + xx[301] - xx[215] - xx[219] - xx[112] + xx[310] - xx[224] - xx[228]
    - xx[149];
  xx[47] = 0.3333333333333333;
  xx[52] = xx[285] - xx[275] - xx[275] - xx[39] + xx[294] - xx[205] - xx[205] -
    xx[77] + xx[303] - xx[217] - xx[217] - xx[114] + xx[47] + xx[312] - xx[226]
    - xx[226] - xx[151];
  xx[53] = xx[286] - xx[276] - xx[278] - xx[40] + xx[295] - xx[206] - xx[208] -
    xx[78] + xx[304] - xx[218] - xx[220] - xx[115] + xx[313] - xx[227] - xx[229]
    - xx[152];
  xx[59] = 0.4333333333333333;
  xx[60] = xx[289] - xx[279] - xx[279] - xx[43] + xx[298] - xx[209] - xx[209] -
    xx[81] + xx[307] - xx[221] - xx[221] - xx[118] + xx[59] + xx[316] - xx[230]
    - xx[230] - xx[155];
  xx[317] = pm_math_Vector3_dot_ra(xx + 15, xx + 178);
  xx[318] = xx[2];
  xx[319] = xx[1];
  xx[320] = xx[251];
  xx[321] = xx[270];
  xx[322] = xx[174];
  xx[323] = xx[2];
  xx[324] = pm_math_Vector3_dot_ra(xx + 182, xx + 185);
  xx[325] = xx[177];
  xx[326] = xx[192];
  xx[327] = xx[194];
  xx[328] = xx[196];
  xx[329] = xx[1];
  xx[330] = xx[177];
  xx[331] = pm_math_Vector3_dot_ra(xx + 188, xx + 11);
  xx[332] = xx[197];
  xx[333] = xx[241];
  xx[334] = xx[242];
  xx[335] = xx[251];
  xx[336] = xx[192];
  xx[337] = xx[197];
  xx[338] = xx[44];
  xx[339] = xx[45];
  xx[340] = xx[46];
  xx[341] = xx[270];
  xx[342] = xx[194];
  xx[343] = xx[241];
  xx[344] = xx[45];
  xx[345] = xx[52];
  xx[346] = xx[53];
  xx[347] = xx[174];
  xx[348] = xx[196];
  xx[349] = xx[242];
  xx[350] = xx[46];
  xx[351] = xx[53];
  xx[352] = xx[60];
  ii[0] = factorSymmetricPosDef(xx + 317, 6, xx + 191);
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'robot_simple_balancing/6-DOF Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[82] = xx[19];
  xx[83] = xx[22];
  xx[84] = xx[26];
  xx[85] = xx[29];
  pm_math_Quaternion_inverseXform_ra(xx + 82, xx + 4, xx + 101);
  xx[1] = xx[25] * inputDot[16];
  xx[2] = xx[0] - xx[3] * xx[27] * xx[27];
  xx[19] = xx[2] * inputDot[17];
  xx[22] = xx[1] + xx[19];
  xx[26] = xx[102] + xx[22];
  xx[29] = xx[31] + xx[30];
  xx[30] = xx[29] * xx[3] * inputDot[16];
  xx[31] = xx[30] + inputDot[18];
  xx[61] = xx[103] + xx[31];
  xx[65] = xx[0] - (xx[21] + xx[34]) * xx[3];
  xx[21] = xx[65] * inputDot[16];
  xx[34] = xx[20] * xx[27];
  xx[20] = xx[3] * xx[34] * inputDot[17];
  xx[27] = xx[21] + xx[20];
  xx[70] = xx[101] + xx[27];
  xx[71] = xx[70] * xx[94];
  xx[89] = (xx[3] * xx[26] * inputDot[19] + xx[61] * xx[71]) * xx[131] - input
    [62];
  xx[119] = xx[27];
  xx[120] = xx[22];
  xx[121] = xx[31];
  pm_math_Vector3_cross_ra(xx + 101, xx + 119, xx + 138);
  xx[156] = xx[21];
  xx[157] = xx[1];
  xx[158] = xx[30];
  pm_math_Vector3_cross_ra(xx + 119, xx + 156, xx + 169);
  xx[1] = xx[170] + xx[20] * inputDot[18];
  xx[20] = xx[25] * inputDdot[16];
  xx[21] = xx[2] * inputDdot[17];
  xx[2] = xx[139] - xx[1] + xx[20] + xx[21];
  pm_math_Vector3_cross_ra(xx + 4, xx + 198, xx + 119);
  pm_math_Vector3_cross_ra(xx + 4, xx + 119, xx + 156);
  pm_math_Quaternion_inverseXform_ra(xx + 82, xx + 156, xx + 119);
  xx[25] = xx[103] + xx[61];
  xx[30] = xx[27] * xx[14];
  xx[27] = xx[119] - xx[25] * xx[30] + xx[1] * xx[14] - xx[14] * xx[20] - xx[14]
    * xx[21];
  xx[1] = xx[26] * xx[94];
  xx[20] = xx[131] * (xx[61] * xx[1] - xx[3] * xx[70] * inputDot[19]) - input[63];
  xx[21] = xx[22] * xx[14];
  xx[22] = xx[19] * inputDot[18] - xx[169];
  xx[19] = xx[65] * inputDdot[16];
  xx[31] = xx[3] * xx[34] * inputDdot[17];
  xx[34] = xx[120] - xx[25] * xx[21] + xx[14] * xx[22] + xx[14] * xx[19] + xx[14]
    * xx[31];
  xx[25] = xx[138] + xx[22] + xx[19] + xx[31];
  xx[156] = xx[89] + xx[2] * xx[181] + xx[28] * xx[27];
  xx[157] = xx[20] + xx[34] * xx[28] - xx[25] * xx[181];
  xx[158] = xx[131] * (inputDdot[19] - (xx[70] * xx[71] + xx[26] * xx[1])) -
    input[64] + ((xx[101] + xx[70]) * xx[30] + (xx[102] + xx[26]) * xx[21] + xx
                 [121]) * xx[28];
  pm_math_Quaternion_xform_ra(xx + 82, xx + 156, xx + 101);
  xx[119] = xx[48];
  xx[120] = xx[51];
  xx[121] = xx[55];
  xx[122] = xx[67];
  pm_math_Quaternion_inverseXform_ra(xx + 119, xx + 4, xx + 156);
  xx[1] = xx[54] * inputDot[12];
  xx[19] = xx[0] - xx[3] * xx[56] * xx[56];
  xx[21] = xx[19] * inputDot[13];
  xx[22] = xx[1] + xx[21];
  xx[30] = xx[157] + xx[22];
  xx[31] = xx[69] + xx[68];
  xx[48] = xx[31] * xx[3] * inputDot[12];
  xx[51] = xx[48] + inputDot[14];
  xx[55] = xx[158] + xx[51];
  xx[65] = xx[0] - (xx[50] + xx[72]) * xx[3];
  xx[50] = xx[65] * inputDot[12];
  xx[67] = xx[49] * xx[56];
  xx[49] = xx[3] * xx[67] * inputDot[13];
  xx[56] = xx[50] + xx[49];
  xx[68] = xx[156] + xx[56];
  xx[69] = xx[68] * xx[57];
  xx[71] = (xx[3] * xx[30] * inputDot[15] + xx[55] * xx[69]) * xx[131] - input
    [50];
  xx[191] = xx[56];
  xx[192] = xx[22];
  xx[193] = xx[51];
  pm_math_Vector3_cross_ra(xx + 156, xx + 191, xx + 194);
  xx[230] = xx[50];
  xx[231] = xx[1];
  xx[232] = xx[48];
  pm_math_Vector3_cross_ra(xx + 191, xx + 230, xx + 233);
  xx[1] = xx[234] + xx[49] * inputDot[14];
  xx[48] = xx[54] * inputDdot[12];
  xx[49] = xx[19] * inputDdot[13];
  xx[19] = xx[195] - xx[1] + xx[48] + xx[49];
  pm_math_Vector3_cross_ra(xx + 4, xx + 210, xx + 191);
  pm_math_Vector3_cross_ra(xx + 4, xx + 191, xx + 230);
  pm_math_Quaternion_inverseXform_ra(xx + 119, xx + 230, xx + 191);
  xx[50] = xx[158] + xx[55];
  xx[51] = xx[56] * xx[14];
  xx[54] = xx[191] - xx[50] * xx[51] + xx[1] * xx[14] - xx[14] * xx[48] - xx[14]
    * xx[49];
  xx[1] = xx[30] * xx[57];
  xx[48] = xx[131] * (xx[55] * xx[1] - xx[3] * xx[68] * inputDot[15]) - input[51];
  xx[49] = xx[22] * xx[14];
  xx[22] = xx[21] * inputDot[14] - xx[233];
  xx[21] = xx[65] * inputDdot[12];
  xx[56] = xx[3] * xx[67] * inputDdot[13];
  xx[65] = xx[192] - xx[50] * xx[49] + xx[14] * xx[22] + xx[14] * xx[21] + xx[14]
    * xx[56];
  xx[50] = xx[194] + xx[22] + xx[21] + xx[56];
  xx[230] = xx[71] + xx[19] * xx[58] + xx[28] * xx[54];
  xx[231] = xx[48] + xx[65] * xx[28] - xx[50] * xx[58];
  xx[232] = xx[131] * (inputDdot[15] - (xx[68] * xx[69] + xx[30] * xx[1])) -
    input[52] + ((xx[156] + xx[68]) * xx[51] + (xx[157] + xx[30]) * xx[49] + xx
                 [193]) * xx[28];
  pm_math_Quaternion_xform_ra(xx + 119, xx + 230, xx + 156);
  xx[236] = xx[66];
  xx[237] = xx[88];
  xx[238] = xx[92];
  xx[239] = xx[104];
  pm_math_Quaternion_inverseXform_ra(xx + 236, xx + 4, xx + 191);
  xx[1] = xx[91] * inputDot[8];
  xx[21] = xx[0] - xx[3] * xx[93] * xx[93];
  xx[22] = xx[21] * inputDot[9];
  xx[49] = xx[1] + xx[22];
  xx[51] = xx[192] + xx[49];
  xx[56] = xx[106] + xx[105];
  xx[66] = xx[56] * xx[3] * inputDot[8];
  xx[67] = xx[66] + inputDot[10];
  xx[69] = xx[193] + xx[67];
  xx[72] = xx[0] - (xx[87] + xx[109]) * xx[3];
  xx[87] = xx[72] * inputDot[8];
  xx[88] = xx[86] * xx[93];
  xx[86] = xx[3] * xx[88] * inputDot[9];
  xx[90] = xx[87] + xx[86];
  xx[92] = xx[191] + xx[90];
  xx[93] = xx[92] * xx[62];
  xx[95] = (xx[3] * xx[51] * inputDot[11] + xx[69] * xx[93]) * xx[131] - input
    [38];
  xx[104] = xx[90];
  xx[105] = xx[49];
  xx[106] = xx[67];
  pm_math_Vector3_cross_ra(xx + 191, xx + 104, xx + 107);
  xx[230] = xx[87];
  xx[231] = xx[1];
  xx[232] = xx[66];
  pm_math_Vector3_cross_ra(xx + 104, xx + 230, xx + 240);
  xx[1] = xx[241] + xx[86] * inputDot[10];
  xx[66] = xx[91] * inputDdot[8];
  xx[67] = xx[21] * inputDdot[9];
  xx[21] = xx[108] - xx[1] + xx[66] + xx[67];
  pm_math_Vector3_cross_ra(xx + 4, xx + 98, xx + 104);
  pm_math_Vector3_cross_ra(xx + 4, xx + 104, xx + 230);
  pm_math_Quaternion_inverseXform_ra(xx + 236, xx + 230, xx + 104);
  xx[86] = xx[193] + xx[69];
  xx[87] = xx[90] * xx[14];
  xx[90] = xx[104] - xx[86] * xx[87] + xx[1] * xx[14] - xx[14] * xx[66] - xx[14]
    * xx[67];
  xx[1] = xx[51] * xx[62];
  xx[66] = xx[131] * (xx[69] * xx[1] - xx[3] * xx[92] * inputDot[11]) - input[39];
  xx[67] = xx[49] * xx[14];
  xx[49] = xx[22] * inputDot[10] - xx[240];
  xx[22] = xx[72] * inputDdot[8];
  xx[72] = xx[3] * xx[88] * inputDdot[9];
  xx[88] = xx[105] - xx[86] * xx[67] + xx[14] * xx[49] + xx[14] * xx[22] + xx[14]
    * xx[72];
  xx[86] = xx[107] + xx[49] + xx[22] + xx[72];
  xx[230] = xx[95] + xx[21] * xx[63] + xx[28] * xx[90];
  xx[231] = xx[66] + xx[88] * xx[28] - xx[86] * xx[63];
  xx[232] = xx[131] * (inputDdot[11] - (xx[92] * xx[93] + xx[51] * xx[1])) -
    input[40] + ((xx[191] + xx[92]) * xx[87] + (xx[192] + xx[51]) * xx[67] + xx
                 [106]) * xx[28];
  pm_math_Quaternion_xform_ra(xx + 236, xx + 230, xx + 104);
  xx[249] = xx[123];
  xx[250] = xx[126];
  xx[251] = xx[129];
  xx[252] = xx[141];
  pm_math_Quaternion_inverseXform_ra(xx + 249, xx + 4, xx + 125);
  xx[1] = xx[128] * inputDot[4];
  xx[22] = xx[0] - xx[3] * xx[130] * xx[130];
  xx[49] = xx[22] * inputDot[5];
  xx[67] = xx[1] + xx[49];
  xx[72] = xx[126] + xx[67];
  xx[87] = xx[143] + xx[142];
  xx[91] = xx[87] * xx[3] * inputDot[4];
  xx[93] = xx[91] + inputDot[6];
  xx[123] = xx[127] + xx[93];
  xx[129] = xx[0] - (xx[18] + xx[146]) * xx[3];
  xx[0] = xx[129] * inputDot[4];
  xx[18] = xx[124] * xx[130];
  xx[124] = xx[3] * xx[18] * inputDot[5];
  xx[130] = xx[0] + xx[124];
  xx[133] = xx[125] + xx[130];
  xx[141] = xx[133] * xx[96];
  xx[142] = (xx[3] * xx[72] * inputDot[7] + xx[123] * xx[141]) * xx[131] -
    input[26];
  xx[143] = xx[130];
  xx[144] = xx[67];
  xx[145] = xx[93];
  pm_math_Vector3_cross_ra(xx + 125, xx + 143, xx + 191);
  xx[230] = xx[0];
  xx[231] = xx[1];
  xx[232] = xx[91];
  pm_math_Vector3_cross_ra(xx + 143, xx + 230, xx + 253);
  xx[0] = xx[254] + xx[124] * inputDot[6];
  xx[1] = xx[128] * inputDdot[4];
  xx[91] = xx[22] * inputDdot[5];
  xx[22] = xx[192] - xx[0] + xx[1] + xx[91];
  pm_math_Vector3_cross_ra(xx + 4, xx + 134, xx + 143);
  pm_math_Vector3_cross_ra(xx + 4, xx + 143, xx + 230);
  pm_math_Quaternion_inverseXform_ra(xx + 249, xx + 230, xx + 143);
  xx[93] = xx[127] + xx[123];
  xx[124] = xx[130] * xx[14];
  xx[127] = xx[143] - xx[93] * xx[124] + xx[0] * xx[14] - xx[14] * xx[1] - xx[14]
    * xx[91];
  xx[0] = xx[72] * xx[96];
  xx[1] = xx[131] * (xx[123] * xx[0] - xx[3] * xx[133] * inputDot[7]) - input[27];
  xx[91] = xx[67] * xx[14];
  xx[67] = xx[49] * inputDot[6] - xx[253];
  xx[49] = xx[129] * inputDdot[4];
  xx[128] = xx[3] * xx[18] * inputDdot[5];
  xx[18] = xx[144] - xx[93] * xx[91] + xx[14] * xx[67] + xx[14] * xx[49] + xx[14]
    * xx[128];
  xx[14] = xx[191] + xx[67] + xx[49] + xx[128];
  xx[128] = xx[142] + xx[22] * xx[97] + xx[28] * xx[127];
  xx[129] = xx[1] + xx[18] * xx[28] - xx[14] * xx[97];
  xx[130] = xx[131] * (inputDdot[7] - (xx[133] * xx[141] + xx[72] * xx[0])) -
    input[28] + ((xx[125] + xx[133]) * xx[124] + (xx[126] + xx[72]) * xx[91] +
                 xx[145]) * xx[28];
  pm_math_Quaternion_xform_ra(xx + 249, xx + 128, xx + 124);
  xx[128] = - state[3];
  xx[129] = - state[4];
  xx[130] = - state[5];
  xx[131] = - state[6];
  xx[143] = state[7];
  xx[144] = state[8];
  xx[145] = state[9];
  pm_math_Quaternion_inverseXform_ra(xx + 128, xx + 143, xx + 230);
  pm_math_Vector3_cross_ra(xx + 4, xx + 230, xx + 128);
  xx[143] = - xx[230];
  xx[144] = - xx[231];
  xx[145] = - xx[232];
  pm_math_Vector3_cross_ra(xx + 4, xx + 143, xx + 230);
  xx[143] = xx[128] + xx[230];
  xx[144] = xx[129] + xx[231];
  xx[145] = xx[130] + xx[232];
  pm_math_Matrix3x3_xform_ra(xx + 160, xx + 143, xx + 128);
  xx[159] = xx[101] + xx[156] + xx[104] + xx[124] + xx[128];
  xx[160] = xx[102] + xx[157] + xx[105] + xx[125] + xx[129];
  xx[161] = xx[103] + xx[158] + xx[106] + xx[126] + xx[130];
  xx[128] = xx[32] * state[10];
  xx[129] = xx[47] * state[11];
  xx[130] = xx[59] * state[12];
  pm_math_Vector3_cross_ra(xx + 4, xx + 128, xx + 162);
  xx[4] = xx[70];
  xx[5] = xx[26];
  xx[6] = xx[61];
  xx[128] = xx[70] * xx[244];
  xx[129] = xx[26] * xx[244];
  xx[130] = xx[61] * xx[248];
  pm_math_Vector3_cross_ra(xx + 4, xx + 128, xx + 165);
  xx[4] = xx[165] - (input[65] + xx[94] * xx[20]) + xx[25] * xx[245] - xx[34] *
    xx[181];
  xx[5] = xx[166] + xx[94] * xx[89] - input[66] + xx[2] * xx[245] + xx[181] *
    xx[27];
  xx[6] = xx[167] - input[67] + (xx[140] - xx[171] + xx[3] * xx[29] * inputDdot
    [16] + inputDdot[18]) * xx[248];
  pm_math_Quaternion_xform_ra(xx + 82, xx + 4, xx + 25);
  pm_math_Vector3_cross_ra(xx + 198, xx + 101, xx + 4);
  xx[82] = xx[68];
  xx[83] = xx[30];
  xx[84] = xx[55];
  xx[101] = xx[68] * xx[244];
  xx[102] = xx[30] * xx[244];
  xx[103] = xx[55] * xx[248];
  pm_math_Vector3_cross_ra(xx + 82, xx + 101, xx + 28);
  xx[82] = xx[28] - (input[53] + xx[57] * xx[48]) + xx[50] * xx[23] - xx[65] *
    xx[58];
  xx[83] = xx[29] + xx[57] * xx[71] - input[54] + xx[19] * xx[23] + xx[58] * xx
    [54];
  xx[84] = xx[30] - input[55] + (xx[196] - xx[235] + xx[3] * xx[31] * inputDdot
    [12] + inputDdot[14]) * xx[248];
  pm_math_Quaternion_xform_ra(xx + 119, xx + 82, xx + 28);
  pm_math_Vector3_cross_ra(xx + 210, xx + 156, xx + 47);
  xx[57] = xx[92];
  xx[58] = xx[51];
  xx[59] = xx[69];
  xx[82] = xx[92] * xx[244];
  xx[83] = xx[51] * xx[244];
  xx[84] = xx[69] * xx[248];
  pm_math_Vector3_cross_ra(xx + 57, xx + 82, xx + 67);
  xx[57] = xx[67] - (input[41] + xx[62] * xx[66]) + xx[86] * xx[24] - xx[88] *
    xx[63];
  xx[58] = xx[68] + xx[62] * xx[95] - input[42] + xx[21] * xx[24] + xx[63] * xx
    [90];
  xx[59] = xx[69] - input[43] + (xx[109] - xx[242] + xx[3] * xx[56] * inputDdot
    [8] + inputDdot[10]) * xx[248];
  pm_math_Quaternion_xform_ra(xx + 236, xx + 57, xx + 19);
  pm_math_Vector3_cross_ra(xx + 98, xx + 104, xx + 54);
  xx[57] = xx[133];
  xx[58] = xx[72];
  xx[59] = xx[123];
  xx[61] = xx[133] * xx[244];
  xx[62] = xx[72] * xx[244];
  xx[63] = xx[123] * xx[248];
  pm_math_Vector3_cross_ra(xx + 57, xx + 61, xx + 65);
  xx[57] = xx[65] - (input[29] + xx[96] * xx[1]) + xx[14] * xx[33] - xx[18] *
    xx[97];
  xx[58] = xx[66] + xx[96] * xx[142] - input[30] + xx[22] * xx[33] + xx[97] *
    xx[127];
  xx[59] = xx[67] - input[31] + (xx[193] - xx[255] + xx[3] * xx[87] * inputDdot
    [4] + inputDdot[6]) * xx[248];
  pm_math_Quaternion_xform_ra(xx + 249, xx + 57, xx + 0);
  pm_math_Vector3_cross_ra(xx + 134, xx + 124, xx + 22);
  xx[82] = xx[132];
  xx[83] = xx[176];
  xx[84] = xx[247];
  xx[85] = xx[256];
  xx[86] = xx[261];
  xx[87] = xx[266];
  xx[88] = xx[64];
  xx[89] = xx[137];
  xx[90] = xx[173];
  pm_math_Matrix3x3_xform_ra(xx + 82, xx + 143, xx + 31);
  xx[65] = - pm_math_Vector3_dot_ra(xx + 15, xx + 159);
  xx[66] = - pm_math_Vector3_dot_ra(xx + 182, xx + 159);
  xx[67] = - pm_math_Vector3_dot_ra(xx + 188, xx + 159);
  xx[68] = - (xx[162] + xx[25] + xx[4] + xx[28] + xx[47] + xx[19] + xx[54] + xx
              [0] + xx[22] + xx[31]);
  xx[69] = - (xx[163] + xx[26] + xx[5] + xx[29] + xx[48] + xx[20] + xx[55] + xx
              [1] + xx[23] + xx[32]);
  xx[70] = - (xx[164] + xx[27] + xx[6] + xx[30] + xx[49] + xx[21] + xx[56] + xx
              [2] + xx[24] + xx[33]);
  solveSymmetricPosDef(xx + 317, xx + 65, 6, 1, xx + 18, xx + 24);
  pm_math_Matrix3x3_xform_ra(xx + 82, xx + 15, xx + 0);
  pm_math_Matrix3x3_xform_ra(xx + 82, xx + 182, xx + 4);
  pm_math_Matrix3x3_xform_ra(xx + 82, xx + 188, xx + 14);
  xx[353] = xx[0];
  xx[354] = xx[4];
  xx[355] = xx[14];
  xx[356] = xx[44];
  xx[357] = xx[45];
  xx[358] = xx[46];
  xx[359] = xx[1];
  xx[360] = xx[5];
  xx[361] = xx[15];
  xx[362] = xx[284] - xx[274] - xx[272] - xx[38] + xx[293] - xx[204] - xx[202] -
    xx[76] + xx[302] - xx[216] - xx[214] - xx[113] + xx[311] - xx[225] - xx[223]
    - xx[150];
  xx[363] = xx[52];
  xx[364] = xx[53];
  xx[365] = xx[2];
  xx[366] = xx[6];
  xx[367] = xx[16];
  xx[368] = xx[287] - xx[277] - xx[273] - xx[41] + xx[296] - xx[207] - xx[203] -
    xx[79] + xx[305] - xx[219] - xx[215] - xx[116] + xx[314] - xx[228] - xx[224]
    - xx[153];
  xx[369] = xx[288] - xx[278] - xx[276] - xx[42] + xx[297] - xx[208] - xx[206] -
    xx[80] + xx[306] - xx[220] - xx[218] - xx[117] + xx[315] - xx[229] - xx[227]
    - xx[154];
  xx[370] = xx[60];
  xx[371] = xx[178];
  xx[372] = xx[185];
  xx[373] = xx[11];
  xx[374] = xx[132];
  xx[375] = xx[256];
  xx[376] = xx[64];
  xx[377] = xx[179];
  xx[378] = xx[186];
  xx[379] = xx[12];
  xx[380] = xx[176];
  xx[381] = xx[261];
  xx[382] = xx[137];
  xx[383] = xx[180];
  xx[384] = xx[187];
  xx[385] = xx[13];
  xx[386] = xx[247];
  xx[387] = xx[266];
  xx[388] = xx[173];
  solveSymmetricPosDef(xx + 317, xx + 353, 6, 6, xx + 24, xx + 11);
  xx[0] = xx[42];
  xx[1] = xx[48];
  xx[2] = xx[54];
  xx[4] = 9.806649999999999;
  xx[5] = xx[4] * state[4];
  xx[6] = xx[4] * state[5];
  xx[11] = xx[3] * (xx[5] * state[6] - xx[6] * state[3]);
  xx[12] = (xx[5] * state[3] + xx[6] * state[6]) * xx[3];
  xx[13] = xx[4] - (xx[5] * state[4] + xx[6] * state[5]) * xx[3];
  xx[3] = xx[43];
  xx[4] = xx[49];
  xx[5] = xx[55];
  xx[14] = xx[44];
  xx[15] = xx[50];
  xx[16] = xx[56];
  xx[60] = xx[45];
  xx[61] = xx[51];
  xx[62] = xx[57];
  xx[63] = xx[46];
  xx[64] = xx[52];
  xx[65] = xx[58];
  xx[24] = xx[47];
  xx[25] = xx[53];
  xx[26] = xx[59];
  deriv[0] = state[7];
  deriv[1] = state[8];
  deriv[2] = state[9];
  deriv[3] = xx[7];
  deriv[4] = xx[8];
  deriv[5] = xx[9];
  deriv[6] = xx[10];
  deriv[7] = xx[18] - pm_math_Vector3_dot_ra(xx + 0, xx + 11);
  deriv[8] = xx[19] - pm_math_Vector3_dot_ra(xx + 3, xx + 11);
  deriv[9] = xx[20] - pm_math_Vector3_dot_ra(xx + 14, xx + 11);
  deriv[10] = xx[21] - pm_math_Vector3_dot_ra(xx + 60, xx + 11);
  deriv[11] = xx[22] - pm_math_Vector3_dot_ra(xx + 63, xx + 11);
  deriv[12] = xx[23] - pm_math_Vector3_dot_ra(xx + 24, xx + 11);
  xx[0] = 1.0e-6;
  ii[0] = (0 != 0 && fabs(cos(input[17])) < xx[0]) ? 1 : 0;
  if (ii[0] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:GimbalLock",
      "'robot_simple_balancing/Subsystem3/Gimbal Joint' is in gimbal lock: the middle revolute angle is +/- 90 degrees, aligning the first and third revolute axes.",
      neDiagMgr);
  }

  ii[1] = (0 != 0 && fabs(cos(input[13])) < xx[0]) ? 1 : 0;
  if (ii[1] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:GimbalLock",
      "'robot_simple_balancing/Subsystem2/Gimbal Joint1' is in gimbal lock: the middle revolute angle is +/- 90 degrees, aligning the first and third revolute axes.",
      neDiagMgr);
  }

  ii[2] = (0 != 0 && fabs(cos(input[9])) < xx[0]) ? 1 : 0;
  if (ii[2] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:GimbalLock",
      "'robot_simple_balancing/Subsystem1/Gimbal Joint2' is in gimbal lock: the middle revolute angle is +/- 90 degrees, aligning the first and third revolute axes.",
      neDiagMgr);
  }

  ii[3] = (0 != 0 && fabs(cos(input[5])) < xx[0]) ? 1 : 0;
  if (ii[3] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:GimbalLock",
      "'robot_simple_balancing/Subsystem/Gimbal Joint3' is in gimbal lock: the middle revolute angle is +/- 90 degrees, aligning the first and third revolute axes.",
      neDiagMgr);
  }

  errorResult[0] = (double) (ii[0] + ii[1] + ii[2] + ii[3]);
  return NULL;
}
