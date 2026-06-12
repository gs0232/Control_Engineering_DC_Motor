/*
 * RunPositionController_dt.h
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
  { (char_T *)(&RunPositionController_B.TransferFcn), 0, 0, 8 },

  { (char_T *)(&RunPositionController_B.desiredvalue), 1, 0, 1 },

  { (char_T *)(&RunPositionController_B.AND3), 8, 0, 2 }
  ,

  { (char_T *)(&RunPositionController_DW.DigitalOutput1_PWORK), 11, 0, 7 },

  { (char_T *)(&RunPositionController_DW.Memory_PreviousInput), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RunPositionController_P.PIDController_D), 0, 0, 20 },

  { (char_T *)(&RunPositionController_P.DigitalOutput1_BitMode), 6, 0, 4 },

  { (char_T *)(&RunPositionController_P.Constant1_Value), 0, 0, 12 },

  { (char_T *)(&RunPositionController_P.Stepfunction_Y0), 1, 0, 2 },

  { (char_T *)(&RunPositionController_P.Memory_InitialCondition), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] RunPositionController_dt.h */
