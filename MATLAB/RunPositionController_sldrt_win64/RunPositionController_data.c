/*
 * RunPositionController_data.c
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

/* Block parameters (default storage) */
P_RunPositionController_T RunPositionController_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S31>/Derivative Gain'
   */
  1.0,

  /* Mask Parameter: FrequencyOutput_Duty
   * Referenced by: '<Root>/Frequency Output'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput_DutyFinalValue
   * Referenced by: '<Root>/Frequency Output'
   */
  0.0,

  /* Mask Parameter: DigitalOutput1_FinalValue
   * Referenced by: '<Root>/Digital Output1'
   */
  0.0,

  /* Mask Parameter: FrequencyOutput_Frequency
   * Referenced by: '<Root>/Frequency Output'
   */
  15000.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  0.1435,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S32>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: DigitalOutput1_InitialValue
   * Referenced by: '<Root>/Digital Output1'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by:
   *   '<S44>/Saturation'
   *   '<S30>/DeadZone'
   */
  -12.0,

  /* Mask Parameter: DigitalOutput1_MaxMissedTicks
   * Referenced by: '<Root>/Digital Output1'
   */
  1.0E+6,

  /* Mask Parameter: FrequencyOutput_MaxMissedTicks
   * Referenced by: '<Root>/Frequency Output'
   */
  10000.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  100000.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S40>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  37.11,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by:
   *   '<S44>/Saturation'
   *   '<S30>/DeadZone'
   */
  12.0,

  /* Mask Parameter: DigitalOutput1_YieldWhenWaiting
   * Referenced by: '<Root>/Digital Output1'
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

  /* Mask Parameter: DigitalOutput1_BitMode
   * Referenced by: '<Root>/Digital Output1'
   */
  0,

  /* Mask Parameter: DigitalOutput1_Channels
   * Referenced by: '<Root>/Digital Output1'
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

  /* Expression: 0
   * Referenced by: '<S28>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/CW'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step function'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -1000.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  1000.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<Root>/CCW'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 1/12
   * Referenced by: '<Root>/Gain'
   */
  0.083333333333333329,

  /* Expression: 0
   * Referenced by: '<S28>/ZeroGain'
   */
  0.0,

  /* Computed Parameter: Stepfunction_Y0
   * Referenced by: '<Root>/Step function'
   */
  0.0F,

  /* Computed Parameter: Stepfunction_YFinal
   * Referenced by: '<Root>/Step function'
   */
  90.0F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S28>/Memory'
   */
  0
};
