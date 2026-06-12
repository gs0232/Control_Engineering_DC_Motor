/*
 * RunPositionController.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RunPositionController".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Jun  2 11:44:27 2026
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RunPositionController.h"
#include "RunPositionController_private.h"
#include "RunPositionController_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  1.0,
  0.0,
  2.0,
  3.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.0001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6321", 4294967295U, 7, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_RunPositionController_T RunPositionController_B;

/* Continuous states */
X_RunPositionController_T RunPositionController_X;

/* Block states (default storage) */
DW_RunPositionController_T RunPositionController_DW;

/* Real-time model */
static RT_MODEL_RunPositionController_T RunPositionController_M_;
RT_MODEL_RunPositionController_T *const RunPositionController_M =
  &RunPositionController_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  RunPositionController_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RunPositionController_output();
  RunPositionController_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RunPositionController_output();
  RunPositionController_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void RunPositionController_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real_T rtb_IntegralGain;
  real_T rtb_SignPreSat;
  real_T rtb_ZeroGain;
  boolean_T rtb_NotEqual;
  if (rtmIsMajorTimeStep(RunPositionController_M)) {
    /* set solver stop time */
    if (!(RunPositionController_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&RunPositionController_M->solverInfo,
                            ((RunPositionController_M->Timing.clockTickH0 + 1) *
        RunPositionController_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&RunPositionController_M->solverInfo,
                            ((RunPositionController_M->Timing.clockTick0 + 1) *
        RunPositionController_M->Timing.stepSize0 +
        RunPositionController_M->Timing.clockTickH0 *
        RunPositionController_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RunPositionController_M)) {
    RunPositionController_M->Timing.t[0] = rtsiGetT
      (&RunPositionController_M->solverInfo);
  }

  /* Step: '<Root>/Step function' */
  if (RunPositionController_M->Timing.t[0] <
      RunPositionController_P.Stepfunction_Time) {
    /* Step: '<Root>/Step function' */
    RunPositionController_B.desiredvalue =
      RunPositionController_P.Stepfunction_Y0;
  } else {
    /* Step: '<Root>/Step function' */
    RunPositionController_B.desiredvalue =
      RunPositionController_P.Stepfunction_YFinal;
  }

  /* End of Step: '<Root>/Step function' */

  /* TransferFcn: '<Root>/Transfer Fcn' */
  RunPositionController_B.TransferFcn = 0.0;
  RunPositionController_B.TransferFcn += RunPositionController_P.TransferFcn_C *
    RunPositionController_X.TransferFcn_CSTATE;

  /* Sum: '<Root>/Sum' */
  RunPositionController_B.error = RunPositionController_B.desiredvalue -
    RunPositionController_B.TransferFcn;

  /* Gain: '<S1>/Gain1' */
  rtb_IntegralGain = RunPositionController_P.Gain1_Gain *
    RunPositionController_B.error;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  Gain: '<S31>/Derivative Gain'
   *  Integrator: '<S32>/Filter'
   *  Sum: '<S32>/SumD'
   */
  RunPositionController_B.FilterCoefficient =
    (RunPositionController_P.PIDController_D * rtb_IntegralGain -
     RunPositionController_X.Filter_CSTATE) *
    RunPositionController_P.PIDController_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  Gain: '<S42>/Proportional Gain'
   *  Integrator: '<S37>/Integrator'
   */
  rtb_SignPreSat = (RunPositionController_P.PIDController_P * rtb_IntegralGain +
                    RunPositionController_X.Integrator_CSTATE) +
    RunPositionController_B.FilterCoefficient;

  /* Saturate: '<S44>/Saturation' */
  if (rtb_SignPreSat >
      RunPositionController_P.PIDController_UpperSaturationLimit) {
    /* Saturate: '<S44>/Saturation' */
    RunPositionController_B.Saturation =
      RunPositionController_P.PIDController_UpperSaturationLimit;
  } else if (rtb_SignPreSat <
             RunPositionController_P.PIDController_LowerSaturationLimit) {
    /* Saturate: '<S44>/Saturation' */
    RunPositionController_B.Saturation =
      RunPositionController_P.PIDController_LowerSaturationLimit;
  } else {
    /* Saturate: '<S44>/Saturation' */
    RunPositionController_B.Saturation = rtb_SignPreSat;
  }

  /* End of Saturate: '<S44>/Saturation' */

  /* Switch: '<Root>/Switch' */
  if (RunPositionController_B.Saturation >
      RunPositionController_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/CW'
     */
    RunPositionController_B.Switch = RunPositionController_P.CW_Value;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/CCW'
     */
    RunPositionController_B.Switch = RunPositionController_P.CCW_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Abs: '<Root>/Abs' */
  rtb_ZeroGain = fabs(RunPositionController_B.Saturation);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_ZeroGain > RunPositionController_P.Saturation_UpperSat) {
    rtb_ZeroGain = RunPositionController_P.Saturation_UpperSat;
  } else {
    if (rtb_ZeroGain < RunPositionController_P.Saturation_LowerSat) {
      rtb_ZeroGain = RunPositionController_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain' */
  RunPositionController_B.Gain = RunPositionController_P.Gain_Gain *
    rtb_ZeroGain;
  if (rtmIsMajorTimeStep(RunPositionController_M)) {
    /* S-Function (sldrtdo): '<Root>/Digital Output1' */
    /* S-Function Block: <Root>/Digital Output1 */
    {
      RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                     &RunPositionController_P.DigitalOutput1_Channels, ((real_T*)
        (&RunPositionController_B.Switch)),
                     &RunPositionController_P.DigitalOutput1_BitMode);
    }

    /* S-Function (sldrtqo): '<Root>/Frequency Output' */
    /* S-Function Block: <Root>/Frequency Output */
    {
      {
        RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                       &RunPositionController_P.FrequencyOutput_Channels,
                       &RunPositionController_P.FrequencyOutput_Frequency,
                       ((real_T*) (&RunPositionController_B.Gain)));
      }
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = RunPositionController_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &RunPositionController_P.EncoderInput_Channels,
                     &rtb_EncoderInput, &parm);
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    if (rtb_EncoderInput > 2.147483648E+9) {
      RunPositionController_B.ENCODER_DEGREE = (rtb_EncoderInput -
        4.294967296E+9) * 360.0 / 2000.0;
    } else {
      RunPositionController_B.ENCODER_DEGREE = rtb_EncoderInput * 360.0 / 2000.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */
  }

  /* Gain: '<S28>/ZeroGain' */
  rtb_ZeroGain = RunPositionController_P.ZeroGain_Gain * rtb_SignPreSat;

  /* DeadZone: '<S30>/DeadZone' */
  if (rtb_SignPreSat >
      RunPositionController_P.PIDController_UpperSaturationLimit) {
    rtb_SignPreSat -= RunPositionController_P.PIDController_UpperSaturationLimit;
  } else if (rtb_SignPreSat >=
             RunPositionController_P.PIDController_LowerSaturationLimit) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= RunPositionController_P.PIDController_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S30>/DeadZone' */

  /* RelationalOperator: '<S28>/NotEqual' */
  rtb_NotEqual = (rtb_ZeroGain != rtb_SignPreSat);

  /* Signum: '<S28>/SignPreSat' */
  if (rtb_SignPreSat < 0.0) {
    rtb_SignPreSat = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    rtb_SignPreSat = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat = (rtNaN);
  }

  /* End of Signum: '<S28>/SignPreSat' */

  /* Gain: '<S34>/Integral Gain' */
  rtb_IntegralGain *= RunPositionController_P.PIDController_I;

  /* DataTypeConversion: '<S28>/DataTypeConv1' */
  if (rtIsNaN(rtb_SignPreSat)) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat = fmod(rtb_SignPreSat, 256.0);
  }

  /* Signum: '<S28>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0) {
    /* DataTypeConversion: '<S28>/DataTypeConv2' */
    rtb_ZeroGain = -1.0;
  } else if (rtb_IntegralGain > 0.0) {
    /* DataTypeConversion: '<S28>/DataTypeConv2' */
    rtb_ZeroGain = 1.0;
  } else if (rtb_IntegralGain == 0.0) {
    /* DataTypeConversion: '<S28>/DataTypeConv2' */
    rtb_ZeroGain = 0.0;
  } else {
    /* DataTypeConversion: '<S28>/DataTypeConv2' */
    rtb_ZeroGain = (rtNaN);
  }

  /* End of Signum: '<S28>/SignPreIntegrator' */

  /* DataTypeConversion: '<S28>/DataTypeConv2' */
  if (rtIsNaN(rtb_ZeroGain)) {
    rtb_ZeroGain = 0.0;
  } else {
    rtb_ZeroGain = fmod(rtb_ZeroGain, 256.0);
  }

  /* Logic: '<S28>/AND3' incorporates:
   *  DataTypeConversion: '<S28>/DataTypeConv1'
   *  DataTypeConversion: '<S28>/DataTypeConv2'
   *  RelationalOperator: '<S28>/Equal1'
   */
  RunPositionController_B.AND3 = (rtb_NotEqual && ((rtb_SignPreSat < 0.0 ?
    (int32_T)(int8_T)-(int8_T)(uint8_T)-rtb_SignPreSat : (int32_T)(int8_T)
    (uint8_T)rtb_SignPreSat) == (rtb_ZeroGain < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-rtb_ZeroGain : (int32_T)(int8_T)(uint8_T)rtb_ZeroGain)));
  if (rtmIsMajorTimeStep(RunPositionController_M)) {
    /* Memory: '<S28>/Memory' */
    RunPositionController_B.Memory =
      RunPositionController_DW.Memory_PreviousInput;
  }

  /* Switch: '<S28>/Switch' */
  if (RunPositionController_B.Memory) {
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant1'
     */
    RunPositionController_B.Switch_l = RunPositionController_P.Constant1_Value;
  } else {
    /* Switch: '<S28>/Switch' */
    RunPositionController_B.Switch_l = rtb_IntegralGain;
  }

  /* End of Switch: '<S28>/Switch' */
}

/* Model update function */
void RunPositionController_update(void)
{
  if (rtmIsMajorTimeStep(RunPositionController_M)) {
    /* Update for Memory: '<S28>/Memory' */
    RunPositionController_DW.Memory_PreviousInput = RunPositionController_B.AND3;
  }

  if (rtmIsMajorTimeStep(RunPositionController_M)) {
    rt_ertODEUpdateContinuousStates(&RunPositionController_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RunPositionController_M->Timing.clockTick0)) {
    ++RunPositionController_M->Timing.clockTickH0;
  }

  RunPositionController_M->Timing.t[0] = rtsiGetSolverStopTime
    (&RunPositionController_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RunPositionController_M->Timing.clockTick1)) {
      ++RunPositionController_M->Timing.clockTickH1;
    }

    RunPositionController_M->Timing.t[1] =
      RunPositionController_M->Timing.clockTick1 *
      RunPositionController_M->Timing.stepSize1 +
      RunPositionController_M->Timing.clockTickH1 *
      RunPositionController_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void RunPositionController_derivatives(void)
{
  XDot_RunPositionController_T *_rtXdot;
  _rtXdot = ((XDot_RunPositionController_T *) RunPositionController_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += RunPositionController_P.TransferFcn_A *
    RunPositionController_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += RunPositionController_B.ENCODER_DEGREE;

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = RunPositionController_B.Switch_l;

  /* Derivatives for Integrator: '<S32>/Filter' */
  _rtXdot->Filter_CSTATE = RunPositionController_B.FilterCoefficient;
}

/* Model initialize function */
void RunPositionController_initialize(void)
{
  /* Start for S-Function (sldrtdo): '<Root>/Digital Output1' */

  /* S-Function Block: <Root>/Digital Output1 */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &RunPositionController_P.DigitalOutput1_Channels,
                   &RunPositionController_P.DigitalOutput1_InitialValue,
                   &RunPositionController_P.DigitalOutput1_BitMode);
  }

  /* Start for S-Function (sldrtqo): '<Root>/Frequency Output' */

  /* S-Function Block: <Root>/Frequency Output */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &RunPositionController_P.FrequencyOutput_Channels,
                     &RunPositionController_P.FrequencyOutput_Frequency,
                     &RunPositionController_P.FrequencyOutput_Duty);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  RunPositionController_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  RunPositionController_X.Integrator_CSTATE =
    RunPositionController_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S32>/Filter' */
  RunPositionController_X.Filter_CSTATE =
    RunPositionController_P.PIDController_InitialConditionForFilter;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = RunPositionController_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &RunPositionController_P.EncoderInput_Channels, NULL, &parm);
  }

  /* InitializeConditions for Memory: '<S28>/Memory' */
  RunPositionController_DW.Memory_PreviousInput =
    RunPositionController_P.Memory_InitialCondition;
}

/* Model terminate function */
void RunPositionController_terminate(void)
{
  /* Terminate for S-Function (sldrtdo): '<Root>/Digital Output1' */

  /* S-Function Block: <Root>/Digital Output1 */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &RunPositionController_P.DigitalOutput1_Channels,
                   &RunPositionController_P.DigitalOutput1_FinalValue,
                   &RunPositionController_P.DigitalOutput1_BitMode);
  }

  /* Terminate for S-Function (sldrtqo): '<Root>/Frequency Output' */

  /* S-Function Block: <Root>/Frequency Output */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &RunPositionController_P.FrequencyOutput_Channels,
                     &RunPositionController_P.FrequencyOutput_Frequency,
                     &RunPositionController_P.FrequencyOutput_DutyFinalValue);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  RunPositionController_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  RunPositionController_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  RunPositionController_initialize();
}

void MdlTerminate(void)
{
  RunPositionController_terminate();
}

/* Registration function */
RT_MODEL_RunPositionController_T *RunPositionController(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  RunPositionController_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)RunPositionController_M, 0,
                sizeof(RT_MODEL_RunPositionController_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RunPositionController_M->solverInfo,
                          &RunPositionController_M->Timing.simTimeStep);
    rtsiSetTPtr(&RunPositionController_M->solverInfo, &rtmGetTPtr
                (RunPositionController_M));
    rtsiSetStepSizePtr(&RunPositionController_M->solverInfo,
                       &RunPositionController_M->Timing.stepSize0);
    rtsiSetdXPtr(&RunPositionController_M->solverInfo,
                 &RunPositionController_M->derivs);
    rtsiSetContStatesPtr(&RunPositionController_M->solverInfo, (real_T **)
                         &RunPositionController_M->contStates);
    rtsiSetNumContStatesPtr(&RunPositionController_M->solverInfo,
      &RunPositionController_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RunPositionController_M->solverInfo,
      &RunPositionController_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RunPositionController_M->solverInfo,
      &RunPositionController_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RunPositionController_M->solverInfo,
      &RunPositionController_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RunPositionController_M->solverInfo,
                          (&rtmGetErrorStatus(RunPositionController_M)));
    rtsiSetRTModelPtr(&RunPositionController_M->solverInfo,
                      RunPositionController_M);
  }

  rtsiSetSimTimeStep(&RunPositionController_M->solverInfo, MAJOR_TIME_STEP);
  RunPositionController_M->intgData.y = RunPositionController_M->odeY;
  RunPositionController_M->intgData.f[0] = RunPositionController_M->odeF[0];
  RunPositionController_M->intgData.f[1] = RunPositionController_M->odeF[1];
  RunPositionController_M->intgData.f[2] = RunPositionController_M->odeF[2];
  RunPositionController_M->contStates = ((real_T *) &RunPositionController_X);
  rtsiSetSolverData(&RunPositionController_M->solverInfo, (void *)
                    &RunPositionController_M->intgData);
  rtsiSetSolverName(&RunPositionController_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RunPositionController_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    RunPositionController_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RunPositionController_M->Timing.sampleTimes =
      (&RunPositionController_M->Timing.sampleTimesArray[0]);
    RunPositionController_M->Timing.offsetTimes =
      (&RunPositionController_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RunPositionController_M->Timing.sampleTimes[0] = (0.0);
    RunPositionController_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    RunPositionController_M->Timing.offsetTimes[0] = (0.0);
    RunPositionController_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(RunPositionController_M, &RunPositionController_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RunPositionController_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    RunPositionController_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RunPositionController_M, 1.5);
  RunPositionController_M->Timing.stepSize0 = 0.0001;
  RunPositionController_M->Timing.stepSize1 = 0.0001;

  /* External mode info */
  RunPositionController_M->Sizes.checksums[0] = (2474985869U);
  RunPositionController_M->Sizes.checksums[1] = (1939361037U);
  RunPositionController_M->Sizes.checksums[2] = (195848055U);
  RunPositionController_M->Sizes.checksums[3] = (2836151371U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    RunPositionController_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RunPositionController_M->extModeInfo,
      &RunPositionController_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RunPositionController_M->extModeInfo,
                        RunPositionController_M->Sizes.checksums);
    rteiSetTPtr(RunPositionController_M->extModeInfo, rtmGetTPtr
                (RunPositionController_M));
  }

  RunPositionController_M->solverInfoPtr = (&RunPositionController_M->solverInfo);
  RunPositionController_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&RunPositionController_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&RunPositionController_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  RunPositionController_M->blockIO = ((void *) &RunPositionController_B);
  (void) memset(((void *) &RunPositionController_B), 0,
                sizeof(B_RunPositionController_T));

  /* parameters */
  RunPositionController_M->defaultParam = ((real_T *)&RunPositionController_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &RunPositionController_X;
    RunPositionController_M->contStates = (x);
    (void) memset((void *)&RunPositionController_X, 0,
                  sizeof(X_RunPositionController_T));
  }

  /* states (dwork) */
  RunPositionController_M->dwork = ((void *) &RunPositionController_DW);
  (void) memset((void *)&RunPositionController_DW, 0,
                sizeof(DW_RunPositionController_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RunPositionController_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  RunPositionController_M->Sizes.numContStates = (3);/* Number of continuous states */
  RunPositionController_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  RunPositionController_M->Sizes.numY = (0);/* Number of model outputs */
  RunPositionController_M->Sizes.numU = (0);/* Number of model inputs */
  RunPositionController_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RunPositionController_M->Sizes.numSampTimes = (2);/* Number of sample times */
  RunPositionController_M->Sizes.numBlocks = (37);/* Number of blocks */
  RunPositionController_M->Sizes.numBlockIO = (11);/* Number of block outputs */
  RunPositionController_M->Sizes.numBlockPrms = (39);/* Sum of parameter "widths" */
  return RunPositionController_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
