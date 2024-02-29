// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2 (win64) Build 3064766 Wed Nov 18 09:12:45 MST 2020
// Date        : Thu Feb 29 21:59:44 2024
// Host        : DennisesLegion running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               C:/Users/denni/Documents/dac70r.github.io/EE2026/Labs/Postlab_Lab3_EE2026/Postlab_Lab3_EE2026.sim/sim_1/impl/timing/xsim/Postlab3_Top_time_impl.v
// Design      : Postlab3_Top
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* ECO_CHECKSUM = "d9e48591" *) 
(* NotValidForBitStream *)
module Postlab3_Top
   (CLOCK,
    LED);
  input CLOCK;
  output [7:0]LED;

  wire CLOCK;
  wire CLOCK_IBUF;
  wire CLOCK_IBUF_BUFG;
  wire [7:0]LED;
  wire [1:0]LED_OBUF;
  wire [0:0]count;
  wire \count[0]_i_2_n_0 ;
  wire \count[0]_i_3_n_0 ;
  wire \count[0]_i_4_n_0 ;
  wire \count[0]_i_5_n_0 ;
  wire \count[0]_i_6_n_0 ;
  wire \count[0]_i_7_n_0 ;
  wire \count[0]_i_8_n_0 ;
  wire \count[0]_i_9_n_0 ;
  wire \count_reg[12]_i_1_n_0 ;
  wire \count_reg[16]_i_1_n_0 ;
  wire \count_reg[20]_i_1_n_0 ;
  wire \count_reg[24]_i_1_n_0 ;
  wire \count_reg[28]_i_1_n_0 ;
  wire \count_reg[4]_i_1_n_0 ;
  wire \count_reg[8]_i_1_n_0 ;
  wire \count_reg_n_0_[0] ;
  wire \count_reg_n_0_[10] ;
  wire \count_reg_n_0_[11] ;
  wire \count_reg_n_0_[12] ;
  wire \count_reg_n_0_[13] ;
  wire \count_reg_n_0_[14] ;
  wire \count_reg_n_0_[15] ;
  wire \count_reg_n_0_[16] ;
  wire \count_reg_n_0_[17] ;
  wire \count_reg_n_0_[18] ;
  wire \count_reg_n_0_[19] ;
  wire \count_reg_n_0_[1] ;
  wire \count_reg_n_0_[20] ;
  wire \count_reg_n_0_[21] ;
  wire \count_reg_n_0_[22] ;
  wire \count_reg_n_0_[23] ;
  wire \count_reg_n_0_[24] ;
  wire \count_reg_n_0_[25] ;
  wire \count_reg_n_0_[26] ;
  wire \count_reg_n_0_[27] ;
  wire \count_reg_n_0_[28] ;
  wire \count_reg_n_0_[29] ;
  wire \count_reg_n_0_[2] ;
  wire \count_reg_n_0_[30] ;
  wire \count_reg_n_0_[31] ;
  wire \count_reg_n_0_[3] ;
  wire \count_reg_n_0_[4] ;
  wire \count_reg_n_0_[5] ;
  wire \count_reg_n_0_[6] ;
  wire \count_reg_n_0_[7] ;
  wire \count_reg_n_0_[8] ;
  wire \count_reg_n_0_[9] ;
  wire [31:1]data0;
  wire slow_clock;
  wire slow_clock_i_1_n_0;
  wire slow_clock_one_i_1_n_0;
  wire slow_clock_one_i_2_n_0;
  wire slow_clock_one_i_3_n_0;
  wire [2:0]\NLW_count_reg[12]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[16]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[20]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[24]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[28]_i_1_CO_UNCONNECTED ;
  wire [3:0]\NLW_count_reg[31]_i_2_CO_UNCONNECTED ;
  wire [3:3]\NLW_count_reg[31]_i_2_O_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[4]_i_1_CO_UNCONNECTED ;
  wire [2:0]\NLW_count_reg[8]_i_1_CO_UNCONNECTED ;

initial begin
 $sdf_annotate("Postlab3_Top_time_impl.sdf",,,,"tool_control");
end
  BUFG CLOCK_IBUF_BUFG_inst
       (.I(CLOCK_IBUF),
        .O(CLOCK_IBUF_BUFG));
  IBUF CLOCK_IBUF_inst
       (.I(CLOCK),
        .O(CLOCK_IBUF));
  OBUF \LED_OBUF[0]_inst 
       (.I(LED_OBUF[0]),
        .O(LED[0]));
  OBUF \LED_OBUF[1]_inst 
       (.I(LED_OBUF[1]),
        .O(LED[1]));
  OBUFT \LED_OBUF[2]_inst 
       (.I(1'b0),
        .O(LED[2]),
        .T(1'b1));
  OBUFT \LED_OBUF[3]_inst 
       (.I(1'b0),
        .O(LED[3]),
        .T(1'b1));
  OBUFT \LED_OBUF[4]_inst 
       (.I(1'b0),
        .O(LED[4]),
        .T(1'b1));
  OBUFT \LED_OBUF[5]_inst 
       (.I(1'b0),
        .O(LED[5]),
        .T(1'b1));
  OBUFT \LED_OBUF[6]_inst 
       (.I(1'b0),
        .O(LED[6]),
        .T(1'b1));
  OBUFT \LED_OBUF[7]_inst 
       (.I(1'b0),
        .O(LED[7]),
        .T(1'b1));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT3 #(
    .INIT(8'h0E)) 
    \count[0]_i_1 
       (.I0(\count[0]_i_2_n_0 ),
        .I1(\count[0]_i_3_n_0 ),
        .I2(\count_reg_n_0_[0] ),
        .O(count));
  LUT4 #(
    .INIT(16'hFFFE)) 
    \count[0]_i_2 
       (.I0(\count[0]_i_4_n_0 ),
        .I1(\count[0]_i_5_n_0 ),
        .I2(\count[0]_i_6_n_0 ),
        .I3(\count[0]_i_7_n_0 ),
        .O(\count[0]_i_2_n_0 ));
  LUT6 #(
    .INIT(64'hFFFFFFFFFBFFFFFF)) 
    \count[0]_i_3 
       (.I0(\count[0]_i_8_n_0 ),
        .I1(\count_reg_n_0_[7] ),
        .I2(\count_reg_n_0_[4] ),
        .I3(\count_reg_n_0_[11] ),
        .I4(\count_reg_n_0_[10] ),
        .I5(\count[0]_i_9_n_0 ),
        .O(\count[0]_i_3_n_0 ));
  LUT4 #(
    .INIT(16'hEFFF)) 
    \count[0]_i_4 
       (.I0(\count_reg_n_0_[9] ),
        .I1(\count_reg_n_0_[8] ),
        .I2(\count_reg_n_0_[14] ),
        .I3(\count_reg_n_0_[12] ),
        .O(\count[0]_i_4_n_0 ));
  LUT6 #(
    .INIT(64'hFFFEFFFFFFFFFFFF)) 
    \count[0]_i_5 
       (.I0(\count_reg_n_0_[30] ),
        .I1(\count_reg_n_0_[31] ),
        .I2(\count_reg_n_0_[28] ),
        .I3(\count_reg_n_0_[29] ),
        .I4(\count_reg_n_0_[6] ),
        .I5(\count_reg_n_0_[5] ),
        .O(\count[0]_i_5_n_0 ));
  LUT4 #(
    .INIT(16'hFFF7)) 
    \count[0]_i_6 
       (.I0(\count_reg_n_0_[25] ),
        .I1(\count_reg_n_0_[22] ),
        .I2(\count_reg_n_0_[27] ),
        .I3(\count_reg_n_0_[26] ),
        .O(\count[0]_i_6_n_0 ));
  LUT4 #(
    .INIT(16'hDFFF)) 
    \count[0]_i_7 
       (.I0(\count_reg_n_0_[15] ),
        .I1(\count_reg_n_0_[16] ),
        .I2(\count_reg_n_0_[19] ),
        .I3(\count_reg_n_0_[17] ),
        .O(\count[0]_i_7_n_0 ));
  LUT4 #(
    .INIT(16'hFFFD)) 
    \count[0]_i_8 
       (.I0(\count_reg_n_0_[18] ),
        .I1(\count_reg_n_0_[13] ),
        .I2(\count_reg_n_0_[21] ),
        .I3(\count_reg_n_0_[20] ),
        .O(\count[0]_i_8_n_0 ));
  LUT5 #(
    .INIT(32'hFFFFFFEF)) 
    \count[0]_i_9 
       (.I0(\count_reg_n_0_[1] ),
        .I1(\count_reg_n_0_[23] ),
        .I2(\count_reg_n_0_[24] ),
        .I3(\count_reg_n_0_[3] ),
        .I4(\count_reg_n_0_[2] ),
        .O(\count[0]_i_9_n_0 ));
  LUT3 #(
    .INIT(8'h01)) 
    \count[31]_i_1 
       (.I0(\count_reg_n_0_[0] ),
        .I1(\count[0]_i_3_n_0 ),
        .I2(\count[0]_i_2_n_0 ),
        .O(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[0] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(count),
        .Q(\count_reg_n_0_[0] ),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[10] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[10]),
        .Q(\count_reg_n_0_[10] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[11] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[11]),
        .Q(\count_reg_n_0_[11] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[12] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[12]),
        .Q(\count_reg_n_0_[12] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[12]_i_1 
       (.CI(\count_reg[8]_i_1_n_0 ),
        .CO({\count_reg[12]_i_1_n_0 ,\NLW_count_reg[12]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[12:9]),
        .S({\count_reg_n_0_[12] ,\count_reg_n_0_[11] ,\count_reg_n_0_[10] ,\count_reg_n_0_[9] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[13] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[13]),
        .Q(\count_reg_n_0_[13] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[14] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[14]),
        .Q(\count_reg_n_0_[14] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[15] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[15]),
        .Q(\count_reg_n_0_[15] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[16] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[16]),
        .Q(\count_reg_n_0_[16] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[16]_i_1 
       (.CI(\count_reg[12]_i_1_n_0 ),
        .CO({\count_reg[16]_i_1_n_0 ,\NLW_count_reg[16]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[16:13]),
        .S({\count_reg_n_0_[16] ,\count_reg_n_0_[15] ,\count_reg_n_0_[14] ,\count_reg_n_0_[13] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[17] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[17]),
        .Q(\count_reg_n_0_[17] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[18] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[18]),
        .Q(\count_reg_n_0_[18] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[19] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[19]),
        .Q(\count_reg_n_0_[19] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[1] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[1]),
        .Q(\count_reg_n_0_[1] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[20] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[20]),
        .Q(\count_reg_n_0_[20] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[20]_i_1 
       (.CI(\count_reg[16]_i_1_n_0 ),
        .CO({\count_reg[20]_i_1_n_0 ,\NLW_count_reg[20]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[20:17]),
        .S({\count_reg_n_0_[20] ,\count_reg_n_0_[19] ,\count_reg_n_0_[18] ,\count_reg_n_0_[17] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[21] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[21]),
        .Q(\count_reg_n_0_[21] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[22] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[22]),
        .Q(\count_reg_n_0_[22] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[23] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[23]),
        .Q(\count_reg_n_0_[23] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[24] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[24]),
        .Q(\count_reg_n_0_[24] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[24]_i_1 
       (.CI(\count_reg[20]_i_1_n_0 ),
        .CO({\count_reg[24]_i_1_n_0 ,\NLW_count_reg[24]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[24:21]),
        .S({\count_reg_n_0_[24] ,\count_reg_n_0_[23] ,\count_reg_n_0_[22] ,\count_reg_n_0_[21] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[25] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[25]),
        .Q(\count_reg_n_0_[25] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[26] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[26]),
        .Q(\count_reg_n_0_[26] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[27] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[27]),
        .Q(\count_reg_n_0_[27] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[28] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[28]),
        .Q(\count_reg_n_0_[28] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[28]_i_1 
       (.CI(\count_reg[24]_i_1_n_0 ),
        .CO({\count_reg[28]_i_1_n_0 ,\NLW_count_reg[28]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[28:25]),
        .S({\count_reg_n_0_[28] ,\count_reg_n_0_[27] ,\count_reg_n_0_[26] ,\count_reg_n_0_[25] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[29] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[29]),
        .Q(\count_reg_n_0_[29] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[2] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[2]),
        .Q(\count_reg_n_0_[2] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[30] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[30]),
        .Q(\count_reg_n_0_[30] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[31] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[31]),
        .Q(\count_reg_n_0_[31] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[31]_i_2 
       (.CI(\count_reg[28]_i_1_n_0 ),
        .CO(\NLW_count_reg[31]_i_2_CO_UNCONNECTED [3:0]),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O({\NLW_count_reg[31]_i_2_O_UNCONNECTED [3],data0[31:29]}),
        .S({1'b0,\count_reg_n_0_[31] ,\count_reg_n_0_[30] ,\count_reg_n_0_[29] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[3] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[3]),
        .Q(\count_reg_n_0_[3] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[4] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[4]),
        .Q(\count_reg_n_0_[4] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[4]_i_1 
       (.CI(1'b0),
        .CO({\count_reg[4]_i_1_n_0 ,\NLW_count_reg[4]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(\count_reg_n_0_[0] ),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[4:1]),
        .S({\count_reg_n_0_[4] ,\count_reg_n_0_[3] ,\count_reg_n_0_[2] ,\count_reg_n_0_[1] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[5] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[5]),
        .Q(\count_reg_n_0_[5] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[6] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[6]),
        .Q(\count_reg_n_0_[6] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[7] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[7]),
        .Q(\count_reg_n_0_[7] ),
        .R(slow_clock));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[8] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[8]),
        .Q(\count_reg_n_0_[8] ),
        .R(slow_clock));
  (* ADDER_THRESHOLD = "35" *) 
  (* OPT_MODIFIED = "SWEEP" *) 
  CARRY4 \count_reg[8]_i_1 
       (.CI(\count_reg[4]_i_1_n_0 ),
        .CO({\count_reg[8]_i_1_n_0 ,\NLW_count_reg[8]_i_1_CO_UNCONNECTED [2:0]}),
        .CYINIT(1'b0),
        .DI({1'b0,1'b0,1'b0,1'b0}),
        .O(data0[8:5]),
        .S({\count_reg_n_0_[8] ,\count_reg_n_0_[7] ,\count_reg_n_0_[6] ,\count_reg_n_0_[5] }));
  FDRE #(
    .INIT(1'b0)) 
    \count_reg[9] 
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(data0[9]),
        .Q(\count_reg_n_0_[9] ),
        .R(slow_clock));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT4 #(
    .INIT(16'hFE01)) 
    slow_clock_i_1
       (.I0(\count_reg_n_0_[0] ),
        .I1(\count[0]_i_3_n_0 ),
        .I2(\count[0]_i_2_n_0 ),
        .I3(LED_OBUF[0]),
        .O(slow_clock_i_1_n_0));
  LUT6 #(
    .INIT(64'hBFFFFFFF40000000)) 
    slow_clock_one_i_1
       (.I0(\count[0]_i_2_n_0 ),
        .I1(slow_clock_one_i_2_n_0),
        .I2(\count_reg_n_0_[0] ),
        .I3(\count_reg_n_0_[1] ),
        .I4(slow_clock_one_i_3_n_0),
        .I5(LED_OBUF[1]),
        .O(slow_clock_one_i_1_n_0));
  LUT6 #(
    .INIT(64'h0000008000000000)) 
    slow_clock_one_i_2
       (.I0(\count_reg_n_0_[20] ),
        .I1(\count_reg_n_0_[21] ),
        .I2(\count_reg_n_0_[13] ),
        .I3(\count_reg_n_0_[18] ),
        .I4(\count_reg_n_0_[24] ),
        .I5(\count_reg_n_0_[23] ),
        .O(slow_clock_one_i_2_n_0));
  LUT6 #(
    .INIT(64'h0000000000002000)) 
    slow_clock_one_i_3
       (.I0(\count_reg_n_0_[4] ),
        .I1(\count_reg_n_0_[7] ),
        .I2(\count_reg_n_0_[2] ),
        .I3(\count_reg_n_0_[3] ),
        .I4(\count_reg_n_0_[11] ),
        .I5(\count_reg_n_0_[10] ),
        .O(slow_clock_one_i_3_n_0));
  FDRE #(
    .INIT(1'b0)) 
    slow_clock_one_reg
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(slow_clock_one_i_1_n_0),
        .Q(LED_OBUF[1]),
        .R(1'b0));
  FDRE #(
    .INIT(1'b0)) 
    slow_clock_reg
       (.C(CLOCK_IBUF_BUFG),
        .CE(1'b1),
        .D(slow_clock_i_1_n_0),
        .Q(LED_OBUF[0]),
        .R(1'b0));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
