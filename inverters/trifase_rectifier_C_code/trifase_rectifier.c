/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trifase_rectifier.c
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

#include "trifase_rectifier.h"
#include "trifase_rectifier_private.h"

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  trifase_rectifier_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  trifase_rectifier_step();
  trifase_rectifier_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  trifase_rectifier_step();
  trifase_rectifier_derivatives();

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

/* Model step function */
void trifase_rectifier_step(void)
{
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    real_T rtb_Gain2;
    real_T rtb_Switch1;
    real_T rtb_Ton;

    /* Outputs for Enabled SubSystem: '<S27>/Signal Generator' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.SignalGenerator_MODE = (rtmIsMajorTimeStep(rtM) ||
        rtDW.SignalGenerator_MODE);
    }

    if (rtDW.SignalGenerator_MODE) {
      boolean_T Frequency_tmp;

      /* Lookup: '<S34>/Look-Up Table' incorporates:
       *  Clock: '<S34>/Clock'
       */
      rtDW.LookUpTable = rt_Lookup(&rtConstP.LookUpTable_XData[0], 8,
        rtM->Timing.t[0], &rtConstP.LookUpTable_YData[0]);
      if (rtmIsMajorTimeStep(rtM)) {
        /* RelationalOperator: '<S29>/Relational Operator' incorporates:
         *  Constant: '<S29>/Constant'
         *  Constant: '<S29>/valp_nom3'
         */
        rtDW.Amplitude = false;

        /* Logic: '<S29>/Logical Operator1' */
        rtDW.LogicalOperator1 = false;

        /* Memory: '<S33>/Memory' */
        rtDW.Memory = rtDW.Memory_PreviousInput;
      }

      /* Step: '<S33>/Step' incorporates:
       *  Step: '<S33>/Step1'
       */
      rtb_Switch1 = rtM->Timing.t[0];
      rtb_Ton = !(rtb_Switch1 < 1.0);

      /* Switch: '<S33>/Switch' */
      rtDW.Switch = (rtb_Ton >= 0.5);

      /* Step: '<S33>/Step1' */
      rtb_Switch1 = (rtb_Switch1 < 2.0);

      /* Switch: '<S33>/Switch2' */
      if (rtb_Switch1 >= 0.5) {
        /* Switch: '<S33>/Switch2' incorporates:
         *  Constant: '<S33>/valp_nom6'
         *  MultiPortSwitch: '<S33>/MULTIPORT SWITCH'
         *  Product: '<S33>/Product2'
         */
        rtDW.Switch2 = 0.5 * rtb_Ton;
      } else {
        /* Switch: '<S33>/Switch2' */
        rtDW.Switch2 = rtDW.Memory;
      }

      /* End of Switch: '<S33>/Switch2' */

      /* Switch: '<S33>/Switch3' incorporates:
       *  DataTypeConversion: '<S33>/Data Type  Conversion2'
       */
      if (rtb_Switch1 != 0.0) {
        rtb_Switch1 = rtDW.Switch2;
      }

      /* End of Switch: '<S33>/Switch3' */
      Frequency_tmp = rtmIsMajorTimeStep(rtM);

      /* RelationalOperator: '<S29>/Relational Operator2' */
      rtDW.Frequency = ((!Frequency_tmp) && rtDW.Frequency);

      /* Switch: '<S29>/Switch4' incorporates:
       *  Constant: '<S29>/Constant5'
       */
      if (rtDW.Frequency) {
        rtb_Gain2 = rtb_Switch1;
      } else {
        rtb_Gain2 = 0.0;
      }

      /* End of Switch: '<S29>/Switch4' */

      /* Gain: '<S29>/Gain2' */
      rtDW.Gain2 = 6.2831853071795862 * rtb_Gain2;

      /* RelationalOperator: '<S29>/Relational Operator1' */
      rtDW.Phase = (Frequency_tmp || rtDW.Phase);

      /* Switch: '<S29>/Switch3' */
      if (rtDW.Phase) {
        /* Switch: '<S29>/Switch3' incorporates:
         *  Gain: '<S29>/Gain4'
         */
        rtDW.Switch3 = 0.017453292519943295 * rtb_Switch1;
      } else {
        /* Switch: '<S29>/Switch3' incorporates:
         *  Constant: '<S29>/Constant4'
         */
        rtDW.Switch3 = 0.0;
      }

      /* End of Switch: '<S29>/Switch3' */

      /* Switch: '<S29>/Switch2' */
      if (rtDW.Amplitude) {
        /* Switch: '<S29>/Switch2' */
        rtDW.Switch2_h = rtb_Switch1;
      } else {
        /* Switch: '<S29>/Switch2' incorporates:
         *  Constant: '<S29>/Constant1'
         */
        rtDW.Switch2_h = 0.0;
      }

      /* End of Switch: '<S29>/Switch2' */

      /* Integrator: '<S29>/Integrator' */
      rtDW.Integrator = rtX.Integrator_CSTATE_l;
    }

    /* End of Outputs for SubSystem: '<S27>/Signal Generator' */

    /* Sum: '<S27>/Sum' incorporates:
     *  Clock: '<S27>/Clock'
     *  Product: '<S27>/Product'
     */
    rtb_Ton = rtM->Timing.t[0] * 314.15926535897933 + rtDW.Integrator;

    /* Outputs for Enabled SubSystem: '<S27>/Harmonic Generator' incorporates:
     *  EnablePort: '<S28>/Enable'
     */
    if (rtmIsMajorTimeStep(rtM) && rtmIsMajorTimeStep(rtM) &&
        rtDW.HarmonicGenerator_MODE) {
      /* Disable for Product: '<S30>/Product1' incorporates:
       *  Outport: '<S28>/harmonic A'
       */
      rtDW.Product1[0] = 0.0;

      /* Disable for Product: '<S31>/Product1' incorporates:
       *  Outport: '<S28>/harmonic B'
       */
      rtDW.Product1_m[0] = 0.0;

      /* Disable for Product: '<S30>/Product1' incorporates:
       *  Outport: '<S28>/harmonic A'
       */
      rtDW.Product1[1] = 0.0;

      /* Disable for Product: '<S31>/Product1' incorporates:
       *  Outport: '<S28>/harmonic B'
       */
      rtDW.Product1_m[1] = 0.0;

      /* Disable for Product: '<S30>/Product1' incorporates:
       *  Outport: '<S28>/harmonic A'
       */
      rtDW.Product1[2] = 0.0;

      /* Disable for Product: '<S31>/Product1' incorporates:
       *  Outport: '<S28>/harmonic B'
       */
      rtDW.Product1_m[2] = 0.0;
      rtDW.HarmonicGenerator_MODE = false;
    }

    if (rtDW.HarmonicGenerator_MODE) {
      int32_T tmp;

      /* Step: '<S28>/Step1' incorporates:
       *  Step: '<S28>/Step'
       */
      rtb_Gain2 = rtM->Timing.t[0];
      if (rtb_Gain2 < 3.0) {
        tmp = 0;
      } else {
        tmp = -1;
      }

      /* End of Step: '<S28>/Step1' */

      /* Sum: '<S28>/Sum4' incorporates:
       *  Step: '<S28>/Step'
       */
      rtb_Switch1 = (real_T)!(rtb_Gain2 < 0.05) + (real_T)tmp;

      /* Product: '<S30>/Product1' incorporates:
       *  Constant: '<S30>/Phase_Harmo1'
       *  Gain: '<S30>/Gain2'
       *  Sum: '<S30>/Sum'
       *  Trigonometry: '<S30>/Trigonometric Function1'
       */
      rtb_Gain2 = sin(3.0 * rtb_Ton + -0.43633231299858238) * (rtb_Switch1 *
        53.11622476544558);

      /* Product: '<S30>/Product1' */
      rtDW.Product1[0] = rtb_Gain2;
      rtDW.Product1[1] = rtb_Gain2;
      rtDW.Product1[2] = rtb_Gain2;

      /* Gain: '<S31>/Gain2' */
      rtb_Gain2 = 2.0 * rtb_Ton;

      /* Product: '<S31>/Product1' incorporates:
       *  Constant: '<S31>/Phase_Harmo1'
       *  Sum: '<S31>/Sum'
       *  Trigonometry: '<S31>/Trigonometric Function1'
       */
      rtDW.Product1_m[0] = rtb_Switch1 * 39.837168574084181 * sin(rtb_Gain2 +
        0.6108652381980153);
      rtDW.Product1_m[1] = sin((rtb_Gain2 + 0.6108652381980153) +
        2.0943951023931953) * (rtb_Switch1 * 39.837168574084181);
      rtDW.Product1_m[2] = sin((rtb_Gain2 + 0.6108652381980153) +
        -2.0943951023931953) * (rtb_Switch1 * 39.837168574084181);
    }

    /* End of Outputs for SubSystem: '<S27>/Harmonic Generator' */

    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/valp_nom2'
     *  Sum: '<S27>/Sum3'
     */
    if (rtDW.LogicalOperator1) {
      rtb_Switch1 = rtDW.LookUpTable;
    } else {
      rtb_Switch1 = rtDW.Switch2_h + 265.58112382722788;
    }

    /* End of Switch: '<S27>/Switch1' */

    /* Sum: '<S27>/Sum5' incorporates:
     *  Constant: '<S27>/P1'
     *  Product: '<S27>/Product1'
     *  Sum: '<S27>/Sum1'
     *  Sum: '<S27>/Sum2'
     *  Switch: '<S27>/Switch5'
     *  Trigonometry: '<S27>/Trigonometric Function'
     */
    rtDW.Sum5[0] = (sin(rtb_Ton + rtDW.Switch3) * rtb_Switch1 + rtDW.Product1[0])
      + rtDW.Product1_m[0];
    rtDW.Sum5[1] = (sin((rtDW.Switch3 + -2.0943951023931953) + rtb_Ton) *
                    rtb_Switch1 + rtDW.Product1[1]) + rtDW.Product1_m[1];
    rtDW.Sum5[2] = (sin((rtDW.Switch3 + 2.0943951023931953) + rtb_Ton) *
                    rtb_Switch1 + rtDW.Product1[2]) + rtDW.Product1_m[2];

    /* S-Function (sfun_spid_contc): '<S39>/State-Space' incorporates:
     *  Constant: '<S15>/(gate)'
     *  Constant: '<S15>/eee'
     *  Constant: '<S17>/(gate)'
     *  Constant: '<S17>/eee'
     *  Constant: '<S19>/(gate)'
     *  Constant: '<S19>/eee'
     *  Constant: '<S21>/(gate)'
     *  Constant: '<S21>/eee'
     *  Constant: '<S23>/(gate)'
     *  Constant: '<S23>/eee'
     *  Constant: '<S25>/(gate)'
     *  Constant: '<S25>/eee'
     */

    /* Level2 S-Function Block: '<S39>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = rtM->childSfunctions[0];
      sfcnOutputs(rts,0);
    }
  }

  if (rtmIsMajorTimeStep(rtM)) {
    real_T *lastU;

    /* Update for Enabled SubSystem: '<S27>/Signal Generator' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    if (rtDW.SignalGenerator_MODE) {
      /* Update for Derivative: '<S34>/Derivative' */
      if (rtDW.TimeStampA == (rtInf)) {
        rtDW.TimeStampA = rtM->Timing.t[0];
        lastU = &rtDW.LastUAtTimeA;
      } else if (rtDW.TimeStampB == (rtInf)) {
        rtDW.TimeStampB = rtM->Timing.t[0];
        lastU = &rtDW.LastUAtTimeB;
      } else if (rtDW.TimeStampA < rtDW.TimeStampB) {
        rtDW.TimeStampA = rtM->Timing.t[0];
        lastU = &rtDW.LastUAtTimeA;
      } else {
        rtDW.TimeStampB = rtM->Timing.t[0];
        lastU = &rtDW.LastUAtTimeB;
      }

      *lastU = rtDW.LookUpTable;

      /* End of Update for Derivative: '<S34>/Derivative' */
      if (rtmIsMajorTimeStep(rtM)) {
        /* Update for Memory: '<S33>/Memory' */
        rtDW.Memory_PreviousInput = rtDW.Switch2;
      }
    }

    /* End of Update for SubSystem: '<S27>/Signal Generator' */

    /* Update for S-Function (sfun_spid_contc): '<S39>/State-Space' incorporates:
     *  Constant: '<S15>/(gate)'
     *  Constant: '<S15>/eee'
     *  Constant: '<S17>/(gate)'
     *  Constant: '<S17>/eee'
     *  Constant: '<S19>/(gate)'
     *  Constant: '<S19>/eee'
     *  Constant: '<S21>/(gate)'
     *  Constant: '<S21>/eee'
     *  Constant: '<S23>/(gate)'
     *  Constant: '<S23>/eee'
     *  Constant: '<S25>/(gate)'
     *  Constant: '<S25>/eee'
     */
    /* Level2 S-Function Block: '<S39>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = rtM->childSfunctions[0];
      sfcnUpdate(rts,0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void trifase_rectifier_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Enabled SubSystem: '<S27>/Signal Generator' */
  if (rtDW.SignalGenerator_MODE) {
    /* Derivatives for Integrator: '<S33>/Integrator' */
    _rtXdot->Integrator_CSTATE = rtDW.Switch;

    /* Derivatives for Integrator: '<S29>/Integrator' */
    _rtXdot->Integrator_CSTATE_l = rtDW.Gain2;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot *) rtM->derivs)->Integrator_CSTATE);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S27>/Signal Generator' */
}

/* Model initialize function */
void trifase_rectifier_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtM->solverInfoPtr = (&rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "rtM points to
       static memory which is guaranteed to be non-NULL" */
    rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rtM->Timing.sampleTimes = (&rtM->Timing.sampleTimesArray[0]);
    rtM->Timing.offsetTimes = (&rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    rtM->Timing.sampleTimes[0] = (0.0);
    rtM->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    rtM->Timing.offsetTimes[0] = (0.0);
    rtM->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.2;
  rtM->solverInfoPtr = (&rtM->solverInfo);
  rtM->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&rtM->solverInfo, 0.2);
  rtsiSetSolverMode(&rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rtM->NonInlinedSFcns.sfcnInfo;
    rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(rtM)));
    rtM->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rtM->Sizes.numSampTimes);
    rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(rtM)[0]);
    rtM->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(rtM)[1]);
    rtssSetTPtrPtr(sfcnInfo,rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(rtM));
    rtssSetStepSizePtr(sfcnInfo, &rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &rtM->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rtM->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &rtM->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rtM->solverInfoPtr);
  }

  rtM->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&rtM->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    rtM->childSfunctions = (&rtM->NonInlinedSFcns.childSFunctionPtrs[0]);
    rtM->childSfunctions[0] = (&rtM->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: trifase_rectifier/<S39>/State-Space (sfun_spid_contc) */
    {
      SimStruct *rts = rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts, &rtM->
        NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &rtM->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &rtM->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts, &rtM->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts, &rtM->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rtM->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &rtDW.Sum5[0];
          sfcnUPtrs[1] = &rtDW.Sum5[1];
          sfcnUPtrs[2] = &rtDW.Sum5[2];
          sfcnUPtrs[3] = &rtConstP.pooled12;
          sfcnUPtrs[4] = &rtConstP.pooled12;
          sfcnUPtrs[5] = &rtConstP.pooled12;
          sfcnUPtrs[6] = &rtConstP.pooled12;
          sfcnUPtrs[7] = &rtConstP.pooled12;
          sfcnUPtrs[8] = &rtConstP.pooled12;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rtM->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &rtConstP.pooled6;
          sfcnUPtrs[1] = &rtConstP.pooled6;
          sfcnUPtrs[2] = &rtConstP.pooled6;
          sfcnUPtrs[3] = &rtConstP.pooled6;
          sfcnUPtrs[4] = &rtConstP.pooled6;
          sfcnUPtrs[5] = &rtConstP.pooled6;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 6);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts, &rtM->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &rtM->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) rtDW.StateSpace_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 12);
          ssSetOutputPortSignal(rts, 1, ((real_T *) rtDW.StateSpace_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts, "trifase_rectifier/powergui/EquivalentModel1/State-Space");
      ssSetRTModel(rts,rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **) &rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtConstP.StateSpace_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtConstP.StateSpace_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtConstInitP.StateSpace_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtConstP.StateSpace_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)rtConstP.StateSpace_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)rtConstP.StateSpace_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)rtConstP.StateSpace_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)rtConstP.StateSpace_P7_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)rtConstP.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)rtConstP.StateSpace_P10_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &rtDW.StateSpace_RWORK[0]);
      ssSetIWork(rts, (int_T *) &rtDW.StateSpace_IWORK[0]);
      ssSetPWork(rts, (void **) &rtDW.StateSpace_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 4);

        /* MODE */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDW.StateSpace_MODE[0]);

        /* RWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rtDW.StateSpace_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 2, 23);
        ssSetDWorkDataType(rts, 2,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &rtDW.StateSpace_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 3, 22);
        ssSetDWorkDataType(rts, 3,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &rtDW.StateSpace_PWORK[0]);
      }

      ssSetModeVector(rts, (int_T *) &rtDW.StateSpace_MODE[0]);

      /* registration */
      sfun_spid_contc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Start for S-Function (sfun_spid_contc): '<S39>/State-Space' incorporates:
   *  Constant: '<S15>/(gate)'
   *  Constant: '<S15>/eee'
   *  Constant: '<S17>/(gate)'
   *  Constant: '<S17>/eee'
   *  Constant: '<S19>/(gate)'
   *  Constant: '<S19>/eee'
   *  Constant: '<S21>/(gate)'
   *  Constant: '<S21>/eee'
   *  Constant: '<S23>/(gate)'
   *  Constant: '<S23>/eee'
   *  Constant: '<S25>/(gate)'
   *  Constant: '<S25>/eee'
   */
  /* Level2 S-Function Block: '<S39>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_spid_contc): '<S39>/State-Space' incorporates:
   *  Constant: '<S15>/(gate)'
   *  Constant: '<S15>/eee'
   *  Constant: '<S17>/(gate)'
   *  Constant: '<S17>/eee'
   *  Constant: '<S19>/(gate)'
   *  Constant: '<S19>/eee'
   *  Constant: '<S21>/(gate)'
   *  Constant: '<S21>/eee'
   *  Constant: '<S23>/(gate)'
   *  Constant: '<S23>/eee'
   *  Constant: '<S25>/(gate)'
   *  Constant: '<S25>/eee'
   */
  /* Level2 S-Function Block: '<S39>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = rtM->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* SystemInitialize for Enabled SubSystem: '<S27>/Signal Generator' */
  /* InitializeConditions for Derivative: '<S34>/Derivative' */
  rtDW.TimeStampA = (rtInf);
  rtDW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  rtX.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S29>/Integrator' */
  rtX.Integrator_CSTATE_l = 0.0;

  /* End of SystemInitialize for SubSystem: '<S27>/Signal Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
