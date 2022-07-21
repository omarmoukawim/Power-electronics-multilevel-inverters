/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trifase_rectifier.h
 *
 * Code generated for Simulink model 'trifase_rectifier'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jul 21 12:10:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_trifase_rectifier_h_
#define RTW_HEADER_trifase_rectifier_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef trifase_rectifier_COMMON_INCLUDES_
#define trifase_rectifier_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* trifase_rectifier_COMMON_INCLUDES_ */

#include "trifase_rectifier_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_look.h"
#include "rt_look1d.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum5[3];                      /* '<S27>/Sum5' */
  real_T StateSpace_o1[5];             /* '<S39>/State-Space' */
  real_T StateSpace_o2[12];            /* '<S39>/State-Space' */
  real_T Product1[3];                  /* '<S30>/Product1' */
  real_T Product1_m[3];                /* '<S31>/Product1' */
  real_T StateSpace_RWORK[2];          /* '<S39>/State-Space' */
  real_T LookUpTable;                  /* '<S34>/Look-Up Table' */
  real_T Switch;                       /* '<S33>/Switch' */
  real_T Memory;                       /* '<S33>/Memory' */
  real_T Switch2;                      /* '<S33>/Switch2' */
  real_T Gain2;                        /* '<S29>/Gain2' */
  real_T Switch3;                      /* '<S29>/Switch3' */
  real_T Switch2_h;                    /* '<S29>/Switch2' */
  real_T Integrator;                   /* '<S29>/Integrator' */
  real_T TimeStampA;                   /* '<S34>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S34>/Derivative' */
  real_T TimeStampB;                   /* '<S34>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S34>/Derivative' */
  real_T Memory_PreviousInput;         /* '<S33>/Memory' */
  void *StateSpace_PWORK[22];          /* '<S39>/State-Space' */
  int_T StateSpace_IWORK[23];          /* '<S39>/State-Space' */
  int_T StateSpace_MODE[7];            /* '<S39>/State-Space' */
  boolean_T Amplitude;                 /* '<S29>/Relational Operator' */
  boolean_T LogicalOperator1;          /* '<S29>/Logical Operator1' */
  boolean_T Frequency;                 /* '<S29>/Relational Operator2' */
  boolean_T Phase;                     /* '<S29>/Relational Operator1' */
  boolean_T SignalGenerator_MODE;      /* '<S27>/Signal Generator' */
  boolean_T HarmonicGenerator_MODE;    /* '<S27>/Harmonic Generator' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S33>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S29>/Integrator' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S33>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S29>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S33>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S29>/Integrator' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S15>/(gate)'
   *   '<S17>/(gate)'
   *   '<S19>/(gate)'
   *   '<S21>/(gate)'
   *   '<S23>/(gate)'
   *   '<S25>/(gate)'
   *   '<S27>/valp_nom'
   *   '<S27>/valp_nom7'
   *   '<S28>/harmonic A'
   *   '<S28>/harmonic B'
   *   '<S28>/Step'
   *   '<S28>/Step1'
   *   '<S29>/signal timer'
   *   '<S29>/Amplitude variation'
   *   '<S29>/Frequency variation'
   *   '<S29>/phase variation'
   *   '<S29>/Constant1'
   *   '<S29>/Constant4'
   *   '<S29>/Constant5'
   *   '<S29>/Integrator'
   *   '<S30>/Phase_Harmo2'
   *   '<S33>/CONSTANT'
   *   '<S33>/Constant1'
   *   '<S33>/Constant4'
   *   '<S33>/Integrator'
   *   '<S33>/Memory'
   *   '<S33>/Step'
   *   '<S33>/Step1'
   *   '<S34>/Hit  Crossing'
   */
  real_T pooled6;

  /* Expression: sps.tv
   * Referenced by: '<S34>/Look-Up Table'
   */
  real_T LookUpTable_XData[8];

  /* Expression: sps.opv
   * Referenced by: '<S34>/Look-Up Table'
   */
  real_T LookUpTable_YData[8];

  /* Pooled Parameter (Expression: Vf)
   * Referenced by:
   *   '<S15>/eee'
   *   '<S17>/eee'
   *   '<S19>/eee'
   *   '<S21>/eee'
   *   '<S23>/eee'
   *   '<S25>/eee'
   */
  real_T pooled12;

  /* Computed Parameter: StateSpace_P1_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P1_Size[2];

  /* Expression: S.Mg
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P1[286];

  /* Computed Parameter: StateSpace_P2_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P2_Size[2];

  /* Expression: [S.nb.x S.nb.u S.nb.y S.nb.s]
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P2[4];

  /* Computed Parameter: StateSpace_P4_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P4_Size[2];

  /* Computed Parameter: StateSpace_P4
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P4[1222];

  /* Computed Parameter: StateSpace_P5_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P5_Size[2];

  /* Expression: S.SwitchVf
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P5[12];

  /* Computed Parameter: StateSpace_P6_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P6_Size[2];

  /* Expression: S.SwitchType
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P6[6];

  /* Pooled Parameter (Expression: )
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P7_Size[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S39>/State-Space'
   */
  real_T pooled13[6];

  /* Computed Parameter: StateSpace_P9_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P9_Size[2];

  /* Expression: S.SaveMatrices
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P9;

  /* Computed Parameter: StateSpace_P10_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P10_Size[2];

  /* Expression: S.BufferSize
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P10;
} ConstP;

/* Constant parameters with dynamic initialization (default storage) */
typedef struct {
  /* Computed Parameter: StateSpace_P3_Size
   * Referenced by: '<S39>/State-Space'
   */
  real_T StateSpace_P3_Size[2];
} ConstInitP;

/* Real-time Model Data Structure */
struct tag_RTM {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[9];
      real_T const *UPtrs1[6];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn0;
  } NonInlinedSFcns;

  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Constant parameters with dynamic initialization (default storage) */
extern ConstInitP rtConstInitP;        /* constant parameters */

/* Model entry point functions */
extern void trifase_rectifier_initialize(void);
extern void trifase_rectifier_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/do not delete this gain' : Unused code path elimination
 * Block '<S15>/Ron' : Unused code path elimination
 * Block '<S15>/Sum' : Unused code path elimination
 * Block '<S17>/Ron' : Unused code path elimination
 * Block '<S17>/Sum' : Unused code path elimination
 * Block '<S19>/Ron' : Unused code path elimination
 * Block '<S19>/Sum' : Unused code path elimination
 * Block '<S21>/Ron' : Unused code path elimination
 * Block '<S21>/Sum' : Unused code path elimination
 * Block '<S23>/Ron' : Unused code path elimination
 * Block '<S23>/Sum' : Unused code path elimination
 * Block '<S25>/Ron' : Unused code path elimination
 * Block '<S25>/Sum' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<S9>/do not delete this gain' : Unused code path elimination
 * Block '<S10>/do not delete this gain' : Unused code path elimination
 * Block '<S11>/do not delete this gain' : Unused code path elimination
 * Block '<S12>/do not delete this gain' : Unused code path elimination
 * Block '<S33>/Data Type  Conversion1' : Eliminate redundant data type conversion
 * Block '<S27>/SinglePhase' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'trifase_rectifier'
 * '<S1>'   : 'trifase_rectifier/Current Measurement1'
 * '<S2>'   : 'trifase_rectifier/Diode1'
 * '<S3>'   : 'trifase_rectifier/Diode2'
 * '<S4>'   : 'trifase_rectifier/Diode4'
 * '<S5>'   : 'trifase_rectifier/Diode5'
 * '<S6>'   : 'trifase_rectifier/Diode6'
 * '<S7>'   : 'trifase_rectifier/Diode7'
 * '<S8>'   : 'trifase_rectifier/Three-Phase Programmable Voltage Source'
 * '<S9>'   : 'trifase_rectifier/Voltage Measurement1'
 * '<S10>'  : 'trifase_rectifier/Voltage Measurement2'
 * '<S11>'  : 'trifase_rectifier/Voltage Measurement3'
 * '<S12>'  : 'trifase_rectifier/Voltage Measurement4'
 * '<S13>'  : 'trifase_rectifier/powergui'
 * '<S14>'  : 'trifase_rectifier/Current Measurement1/Model'
 * '<S15>'  : 'trifase_rectifier/Diode1/Model'
 * '<S16>'  : 'trifase_rectifier/Diode1/Model/Measurement list'
 * '<S17>'  : 'trifase_rectifier/Diode2/Model'
 * '<S18>'  : 'trifase_rectifier/Diode2/Model/Measurement list'
 * '<S19>'  : 'trifase_rectifier/Diode4/Model'
 * '<S20>'  : 'trifase_rectifier/Diode4/Model/Measurement list'
 * '<S21>'  : 'trifase_rectifier/Diode5/Model'
 * '<S22>'  : 'trifase_rectifier/Diode5/Model/Measurement list'
 * '<S23>'  : 'trifase_rectifier/Diode6/Model'
 * '<S24>'  : 'trifase_rectifier/Diode6/Model/Measurement list'
 * '<S25>'  : 'trifase_rectifier/Diode7/Model'
 * '<S26>'  : 'trifase_rectifier/Diode7/Model/Measurement list'
 * '<S27>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model'
 * '<S28>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Harmonic Generator'
 * '<S29>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Signal Generator'
 * '<S30>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Harmonic Generator/Harmonic A generation'
 * '<S31>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Harmonic Generator/Harmonic B generation'
 * '<S32>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Signal Generator/Stair Generator'
 * '<S33>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Signal Generator/Variation SubSystem'
 * '<S34>'  : 'trifase_rectifier/Three-Phase Programmable Voltage Source/Model/Signal Generator/Stair Generator/Model'
 * '<S35>'  : 'trifase_rectifier/Voltage Measurement1/Model'
 * '<S36>'  : 'trifase_rectifier/Voltage Measurement2/Model'
 * '<S37>'  : 'trifase_rectifier/Voltage Measurement3/Model'
 * '<S38>'  : 'trifase_rectifier/Voltage Measurement4/Model'
 * '<S39>'  : 'trifase_rectifier/powergui/EquivalentModel1'
 * '<S40>'  : 'trifase_rectifier/powergui/EquivalentModel1/Gates'
 * '<S41>'  : 'trifase_rectifier/powergui/EquivalentModel1/Sources'
 * '<S42>'  : 'trifase_rectifier/powergui/EquivalentModel1/Status'
 * '<S43>'  : 'trifase_rectifier/powergui/EquivalentModel1/Yout'
 */
#endif                                 /* RTW_HEADER_trifase_rectifier_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
