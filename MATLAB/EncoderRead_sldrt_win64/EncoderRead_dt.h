/*
 * EncoderRead_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&EncoderRead_B.Product), 0, 0, 4 },

  { (char_T *)(&EncoderRead_B.SpeedToCount), 7, 0, 1 }
  ,

  { (char_T *)(&EncoderRead_DW.DigitalOutput_PWORK), 11, 0, 5 },

  { (char_T *)(&EncoderRead_DW.Delay_DSTATE[0]), 7, 0, 301 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&EncoderRead_P.FrequencyOutput_Duty), 0, 0, 12 },

  { (char_T *)(&EncoderRead_P.DigitalOutput_BitMode), 6, 0, 4 },

  { (char_T *)(&EncoderRead_P.DutyCycle_Value), 0, 0, 6 },

  { (char_T *)(&EncoderRead_P.CCW_Value), 1, 0, 2 },

  { (char_T *)(&EncoderRead_P.SpeedToCount_Gain), 7, 0, 2 },

  { (char_T *)(&EncoderRead_P.ManualSwitch_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] EncoderRead_dt.h */
