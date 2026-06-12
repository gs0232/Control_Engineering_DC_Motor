/*
 * EncoderRead.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "EncoderRead".
 *
 * Model version              : 1.13
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Jun  2 10:03:12 2026
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EncoderRead.h"
#include "EncoderRead_private.h"
#include "EncoderRead_dt.h"

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
B_EncoderRead_T EncoderRead_B;

/* Block states (default storage) */
DW_EncoderRead_T EncoderRead_DW;

/* Real-time model */
static RT_MODEL_EncoderRead_T EncoderRead_M_;
RT_MODEL_EncoderRead_T *const EncoderRead_M = &EncoderRead_M_;

/* Model output function */
void EncoderRead_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput;
  real32_T rtb_ManualSwitch;
  real_T tmp;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (EncoderRead_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/CCW'
     */
    rtb_ManualSwitch = EncoderRead_P.CCW_Value;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/CW'
     */
    rtb_ManualSwitch = EncoderRead_P.CW_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Step: '<Root>/Step' */
  if (EncoderRead_M->Timing.t[0] < EncoderRead_P.Step_Time) {
    tmp = EncoderRead_P.Step_Y0;
  } else {
    tmp = EncoderRead_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Duty Cycle'
   */
  EncoderRead_B.Product = EncoderRead_P.DutyCycle_Value * tmp;

  /* Gain: '<Root>/Gain' */
  EncoderRead_B.Gain = EncoderRead_P.Gain_Gain * EncoderRead_B.Product;

  /* S-Function (sldrtdo): '<Root>/Digital Output' */
  /* S-Function Block: <Root>/Digital Output */
  {
    double doval[1];
    double* dovalp = doval;
    *dovalp++ = (double) rtb_ManualSwitch;
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &EncoderRead_P.DigitalOutput_Channels, doval,
                   &EncoderRead_P.DigitalOutput_BitMode);
  }

  /* S-Function (sldrtqo): '<Root>/Frequency Output' */
  /* S-Function Block: <Root>/Frequency Output */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &EncoderRead_P.FrequencyOutput_Channels,
                     &EncoderRead_P.FrequencyOutput_Frequency, ((real_T*)
        (&EncoderRead_B.Product)));
    }
  }

  /* S-Function (sldrtei): '<Root>/Encoder Input' */
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = EncoderRead_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                   &EncoderRead_P.EncoderInput_Channels, &rtb_EncoderInput,
                   &parm);
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  if (rtb_EncoderInput > 2.147483648E+9) {
    EncoderRead_B.ENCODER_DEGREE = (rtb_EncoderInput - 4.294967296E+9) * 360.0 /
      2000.0;
  } else {
    EncoderRead_B.ENCODER_DEGREE = rtb_EncoderInput * 360.0 / 2000.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Gain: '<S2>/SpeedToCount' */
  tmp = trunc((real_T)EncoderRead_P.SpeedToCount_Gain *
              EncoderRead_B.ENCODER_DEGREE);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* Gain: '<S2>/SpeedToCount' */
  EncoderRead_B.SpeedToCount = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp :
    (uint32_T)tmp;

  /* Gain: '<S2>/SpeedGain' incorporates:
   *  Delay: '<S2>/Delay'
   *  Sum: '<S2>/SpeedCount'
   */
  EncoderRead_B.SpeedGain = (real_T)((int32_T)EncoderRead_B.SpeedToCount -
    (int32_T)EncoderRead_DW.Delay_DSTATE[EncoderRead_DW.CircBufIdx]) *
    EncoderRead_P.SpeedGain_Gain;
}

/* Model update function */
void EncoderRead_update(void)
{
  /* Update for Delay: '<S2>/Delay' */
  EncoderRead_DW.Delay_DSTATE[EncoderRead_DW.CircBufIdx] =
    EncoderRead_B.SpeedToCount;
  if (EncoderRead_DW.CircBufIdx < 299U) {
    EncoderRead_DW.CircBufIdx++;
  } else {
    EncoderRead_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S2>/Delay' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++EncoderRead_M->Timing.clockTick0)) {
    ++EncoderRead_M->Timing.clockTickH0;
  }

  EncoderRead_M->Timing.t[0] = EncoderRead_M->Timing.clockTick0 *
    EncoderRead_M->Timing.stepSize0 + EncoderRead_M->Timing.clockTickH0 *
    EncoderRead_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++EncoderRead_M->Timing.clockTick1)) {
      ++EncoderRead_M->Timing.clockTickH1;
    }

    EncoderRead_M->Timing.t[1] = EncoderRead_M->Timing.clockTick1 *
      EncoderRead_M->Timing.stepSize1 + EncoderRead_M->Timing.clockTickH1 *
      EncoderRead_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void EncoderRead_initialize(void)
{
  /* Start for S-Function (sldrtdo): '<Root>/Digital Output' */

  /* S-Function Block: <Root>/Digital Output */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &EncoderRead_P.DigitalOutput_Channels,
                   &EncoderRead_P.DigitalOutput_InitialValue,
                   &EncoderRead_P.DigitalOutput_BitMode);
  }

  /* Start for S-Function (sldrtqo): '<Root>/Frequency Output' */

  /* S-Function Block: <Root>/Frequency Output */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &EncoderRead_P.FrequencyOutput_Channels,
                     &EncoderRead_P.FrequencyOutput_Frequency,
                     &EncoderRead_P.FrequencyOutput_Duty);
    }
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = EncoderRead_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                     &EncoderRead_P.EncoderInput_Channels, NULL, &parm);
    }

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 300; i++) {
      EncoderRead_DW.Delay_DSTATE[i] = EncoderRead_P.Delay_InitialCondition;
    }

    EncoderRead_DW.CircBufIdx = 0U;

    /* End of InitializeConditions for Delay: '<S2>/Delay' */
  }
}

/* Model terminate function */
void EncoderRead_terminate(void)
{
  /* Terminate for S-Function (sldrtdo): '<Root>/Digital Output' */

  /* S-Function Block: <Root>/Digital Output */
  {
    RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 1,
                   &EncoderRead_P.DigitalOutput_Channels,
                   &EncoderRead_P.DigitalOutput_FinalValue,
                   &EncoderRead_P.DigitalOutput_BitMode);
  }

  /* Terminate for S-Function (sldrtqo): '<Root>/Frequency Output' */

  /* S-Function Block: <Root>/Frequency Output */
  {
    {
      RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                     &EncoderRead_P.FrequencyOutput_Channels,
                     &EncoderRead_P.FrequencyOutput_Frequency,
                     &EncoderRead_P.FrequencyOutput_DutyFinalValue);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  EncoderRead_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  EncoderRead_update();
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
  EncoderRead_initialize();
}

void MdlTerminate(void)
{
  EncoderRead_terminate();
}

/* Registration function */
RT_MODEL_EncoderRead_T *EncoderRead(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  EncoderRead_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)EncoderRead_M, 0,
                sizeof(RT_MODEL_EncoderRead_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&EncoderRead_M->solverInfo,
                          &EncoderRead_M->Timing.simTimeStep);
    rtsiSetTPtr(&EncoderRead_M->solverInfo, &rtmGetTPtr(EncoderRead_M));
    rtsiSetStepSizePtr(&EncoderRead_M->solverInfo,
                       &EncoderRead_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&EncoderRead_M->solverInfo, (&rtmGetErrorStatus
      (EncoderRead_M)));
    rtsiSetRTModelPtr(&EncoderRead_M->solverInfo, EncoderRead_M);
  }

  rtsiSetSimTimeStep(&EncoderRead_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&EncoderRead_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = EncoderRead_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    EncoderRead_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    EncoderRead_M->Timing.sampleTimes = (&EncoderRead_M->
      Timing.sampleTimesArray[0]);
    EncoderRead_M->Timing.offsetTimes = (&EncoderRead_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    EncoderRead_M->Timing.sampleTimes[0] = (0.0);
    EncoderRead_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    EncoderRead_M->Timing.offsetTimes[0] = (0.0);
    EncoderRead_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(EncoderRead_M, &EncoderRead_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = EncoderRead_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    EncoderRead_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(EncoderRead_M, 1.5);
  EncoderRead_M->Timing.stepSize0 = 0.0001;
  EncoderRead_M->Timing.stepSize1 = 0.0001;

  /* External mode info */
  EncoderRead_M->Sizes.checksums[0] = (2442849192U);
  EncoderRead_M->Sizes.checksums[1] = (3220488354U);
  EncoderRead_M->Sizes.checksums[2] = (3323762661U);
  EncoderRead_M->Sizes.checksums[3] = (482575121U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    EncoderRead_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(EncoderRead_M->extModeInfo,
      &EncoderRead_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(EncoderRead_M->extModeInfo,
                        EncoderRead_M->Sizes.checksums);
    rteiSetTPtr(EncoderRead_M->extModeInfo, rtmGetTPtr(EncoderRead_M));
  }

  EncoderRead_M->solverInfoPtr = (&EncoderRead_M->solverInfo);
  EncoderRead_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&EncoderRead_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&EncoderRead_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  EncoderRead_M->blockIO = ((void *) &EncoderRead_B);
  (void) memset(((void *) &EncoderRead_B), 0,
                sizeof(B_EncoderRead_T));

  /* parameters */
  EncoderRead_M->defaultParam = ((real_T *)&EncoderRead_P);

  /* states (dwork) */
  EncoderRead_M->dwork = ((void *) &EncoderRead_DW);
  (void) memset((void *)&EncoderRead_DW, 0,
                sizeof(DW_EncoderRead_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    EncoderRead_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  EncoderRead_M->Sizes.numContStates = (0);/* Number of continuous states */
  EncoderRead_M->Sizes.numY = (0);     /* Number of model outputs */
  EncoderRead_M->Sizes.numU = (0);     /* Number of model inputs */
  EncoderRead_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  EncoderRead_M->Sizes.numSampTimes = (2);/* Number of sample times */
  EncoderRead_M->Sizes.numBlocks = (20);/* Number of blocks */
  EncoderRead_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  EncoderRead_M->Sizes.numBlockPrms = (27);/* Sum of parameter "widths" */
  return EncoderRead_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
