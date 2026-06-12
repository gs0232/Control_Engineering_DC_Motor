/*
 * EncoderRead_data.c
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

/* Block parameters (default storage) */
P_EncoderRead_T EncoderRead_P = {
  /* Mask Parameter: FrequencyOutput_Duty
   * Referenced by: '<Root>/Frequency Output'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput_DutyFinalValue
   * Referenced by: '<Root>/Frequency Output'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_FinalValue
   * Referenced by: '<Root>/Digital Output'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput_Frequency
   * Referenced by: '<Root>/Frequency Output'
   */
  15000.0,

  /* Mask Parameter: DigitalOutput_InitialValue
   * Referenced by: '<Root>/Digital Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_MaxMissedTicks
   * Referenced by: '<Root>/Digital Output'
   */
  10000.0,

  /* Mask Parameter: FrequencyOutput_MaxMissedTicks
   * Referenced by: '<Root>/Frequency Output'
   */
  100000.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10000.0,

  /* Mask Parameter: DigitalOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Digital Output'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Frequency Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_BitMode
   * Referenced by: '<Root>/Digital Output'
   */
  0,

  /* Mask Parameter: DigitalOutput_Channels
   * Referenced by: '<Root>/Digital Output'
   */
  0,

  /* Mask Parameter: FrequencyOutput_Channels
   * Referenced by: '<Root>/Frequency Output'
   */
  1,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Expression: 1
   * Referenced by: '<Root>/Duty Cycle'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 12
   * Referenced by: '<Root>/Gain'
   */
  12.0,

  /* Expression: 60/(DelayLength*SampleTimeAsync(1)*4294967296)
   * Referenced by: '<S2>/SpeedGain'
   */
  4.656612873077392E-7,

  /* Computed Parameter: CCW_Value
   * Referenced by: '<Root>/CCW'
   */
  0.0F,

  /* Computed Parameter: CW_Value
   * Referenced by: '<Root>/CW'
   */
  1.0F,

  /* Expression: uint32(4294967296/360)
   * Referenced by: '<S2>/SpeedToCount'
   */
  11930465U,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
