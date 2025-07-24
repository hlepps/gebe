#include "InstructionProcessor.h"

#include <exception>
#include <format>
#include <string>
#include <iostream>
#include "Emulator.h"
#include "OPCodeTable.h"
#include "Useful.h"
#include "Offsets.h"

int InstructionProcessor::ProcessNextInstruction()
{
	try {

		unsigned char inst = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->pc];
		//std::cout << "PC: " << ToHex(registers->pc) << " | Current instruction:" << ToHex(inst) << std::endl;
		//std::cout << "B: " << ToHex(registers->b) << std::endl;
		//std::cout << "z: " << processorFlags.zeroFlag << std::endl;
		registers->pc++;
		switch (inst)
		{
#pragma region 8 bit loads
		case(LD_A_n):
		{
			unsigned char n1 = GetData();
			registers->a = n1;
			return 8;
		}break;
		case(LD_B_n):
		{
			unsigned char n1 = GetData();
			registers->b = n1;
			return 8;
		}break;
		case(LD_C_n):
		{
			unsigned char n1 = GetData();
			registers->c = n1;
			return 8;
		}break;
		case(LD_D_n):
		{
			unsigned char n1 = GetData();
			registers->d = n1;
			return 8;
		}break;
		case(LD_E_n):
		{
			unsigned char n1 = GetData();
			registers->e = n1;
			return 8;
		}break;
		case(LD_H_n):
		{
			unsigned char n1 = GetData();
			registers->h = n1;
			return 8;
		}break;
		case(LD_L_n):
		{
			unsigned char n1 = GetData();
			registers->l = n1;
			return 8;
		}break;

		case (LD_A_A):
		{
			registers->a = registers->a;
			return 4;
		}break;
		case (LD_A_B):
		{
			registers->a = registers->b;
			return 4;
		}break;
		case (LD_A_C):
		{
			registers->a = registers->c;
			return 4;
		}break;
		case (LD_A_D):
		{
			registers->a = registers->d;
			return 4;
		}break;
		case (LD_A_E):
		{
			registers->a = registers->e;
			return 4;
		}break;
		case (LD_A_H):
		{
			registers->a = registers->h;
			return 4;
		}break;
		case (LD_A_L):
		{
			registers->a = registers->l;
			return 4;
		}break;
		case (LD_A_HL_VAL):
		{
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_B_A):
		{
			registers->b = registers->a;
			return 4;
		}break;
		case (LD_B_B):
		{
			registers->b = registers->b;
			return 4;
		}break;
		case (LD_B_C):
		{
			registers->b = registers->c;
			return 4;
		}break;
		case (LD_B_D):
		{
			registers->b = registers->d;
			return 4;
		}break;
		case (LD_B_E):
		{
			registers->b = registers->e;
			return 4;
		}break;
		case (LD_B_H):
		{
			registers->b = registers->h;
			return 4;
		}break;
		case (LD_B_L):
		{
			registers->b = registers->l;
			return 4;
		}break;
		case (LD_B_HL_VAL):
		{
			registers->b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_C_A):
		{
			registers->c = registers->a;
			return 4;
		}break;
		case (LD_C_B):
		{
			registers->c = registers->b;
			return 4;
		}break;
		case (LD_C_C):
		{
			registers->c = registers->c;
			return 4;
		}break;
		case (LD_C_D):
		{
			registers->c = registers->d;
			return 4;
		}break;
		case (LD_C_E):
		{
			registers->c = registers->e;
			return 4;
		}break;
		case (LD_C_H):
		{
			registers->c = registers->h;
			return 4;
		}break;
		case (LD_C_L):
		{
			registers->c = registers->l;
			return 4;
		}break;
		case (LD_C_HL_VAL):
		{
			registers->c = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_D_A):
		{
			registers->d = registers->a;
			return 4;
		}break;
		case (LD_D_B):
		{
			registers->d = registers->b;
			return 4;
		}break;
		case (LD_D_C):
		{
			registers->d = registers->c;
			return 4;
		}break;
		case (LD_D_D):
		{
			registers->d = registers->d;
			return 4;
		}break;
		case (LD_D_E):
		{
			registers->d = registers->e;
			return 4;
		}break;
		case (LD_D_H):
		{
			registers->d = registers->h;
			return 4;
		}break;
		case (LD_D_L):
		{
			registers->d = registers->l;
			return 4;
		}break;
		case (LD_D_HL_VAL):
		{
			registers->d = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_H_A):
		{
			registers->h = registers->a;
			return 4;
		}break;
		case (LD_H_B):
		{
			registers->h = registers->b;
			return 4;
		}break;
		case (LD_H_C):
		{
			registers->h = registers->c;
			return 4;
		}break;
		case (LD_H_D):
		{
			registers->h = registers->d;
			return 4;
		}break;
		case (LD_H_E):
		{
			registers->h = registers->e;
			return 4;
		}break;
		case (LD_H_H):
		{
			registers->h = registers->h;
			return 4;
		}break;
		case (LD_H_L):
		{
			registers->h = registers->l;
			return 4;
		}break;
		case (LD_H_HL_VAL):
		{
			registers->h = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_L_A):
		{
			registers->l = registers->a;
			return 4;
		}break;
		case (LD_L_B):
		{
			registers->l = registers->b;
			return 4;
		}break;
		case (LD_L_C):
		{
			registers->l = registers->c;
			return 4;
		}break;
		case (LD_L_D):
		{
			registers->l = registers->d;
			return 4;
		}break;
		case (LD_L_E):
		{
			registers->l = registers->e;
			return 4;
		}break;
		case (LD_L_H):
		{
			registers->l = registers->h;
			return 4;
		}break;
		case (LD_L_L):
		{
			registers->l = registers->l;
			return 4;
		}break;
		case (LD_L_HL_VAL):
		{
			registers->c = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			return 8;
		}break;

		case (LD_HL_A):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->a;
			return 4;
		}break;
		case (LD_HL_B):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->b;
			return 8;
		}break;
		case (LD_HL_C):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->c;
			return 8;
		}break;
		case (LD_HL_D):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->d;
			return 8;
		}break;
		case (LD_HL_E):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->e;
			return 8;
		}break;
		case (LD_HL_H):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->h;
			return 8;
		}break;
		case (LD_HL_L):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->l;
			return 8;
		}break;
		case (LD_HL_n):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = GetData();
			return 12;
		}break;

		case (LD_A_BC):
		{
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->bc];
			return 8;
		}break;
		case (LD_A_DE):
		{
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->de];
			return 8;
		}break;
		case (LD_A_nn):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[combineChars(n2, n1)];
			return 16;
		}break;

		case (LD_BC_A):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->bc] = registers->a;
			return 8;
		}break;
		case (LD_DE_A):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->de] = registers->a;
			return 8;
		}break;
		case (LD_nn_A):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			Emulator::GetInstance().GetMemoryManagerRef().memory[combineChars(n2, n1)] = registers->a;
			return 16;
		}break;

		case(LD_A_C_VAL):
		{
			unsigned short addr = Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] + registers->c;
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[addr];
			return 8;
		}break;

		case(LDH_C_A):
		{
			unsigned short addr = Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] + registers->c;
			Emulator::GetInstance().GetMemoryManagerRef().memory[addr] = registers->a;
			return 8;
		}break;

		case(LDD_A_HL):
		{
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			registers->hl--;
			return 8;
		}break;
		case(LDD_HL_A):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->a;
			registers->hl--;
			return 8;
		}break;
		case(LDI_A_HL):
		{
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl];
			registers->hl++;
			return 8;
		}break;
		case(LDI_HL_A):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = registers->a;
			registers->hl++;
			return 8;
		}break;

		case(LDH_n_A):
		{
			unsigned short addr = Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] + GetData();
			Emulator::GetInstance().GetMemoryManagerRef().memory[addr] = registers->a;
			return 12;
		}break;
		case(LDH_A_n):
		{
			unsigned short addr = Emulator::GetInstance().GetMemoryManagerRef().memory[0xFF00] + GetData();
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[addr];
			return 12;
		}break;
#pragma endregion
#pragma region 16 bit loads
		case (LD_BC_nn):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			unsigned short val = combineChars(n2, n1);
			registers->bc = val;
			return 12;
		}break;
		case (LD_DE_nn):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			unsigned short val = combineChars(n2, n1);
			registers->de = val;
			return 12;
		}break;
		case (LD_HL_nn):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			unsigned short val = combineChars(n2, n1);
			registers->hl = val;
			return 12;
		}break;
		case (LD_SP_nn):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			unsigned short val = combineChars(n2, n1);
			registers->sp = val;
			return 12;
		}break;
		case (LD_SP_HL):
		{
			registers->sp = registers->hl;
			return 8;
		}break;
		case (LDHL_SP_d):
		{
			unsigned char data = GetData();
			registers->hl = registers->sp + data;
			processorFlags.zeroFlag = 0;
			processorFlags.subtractionFlag = 0;
			processorFlags.halfCarryFlag = ((registers->sp & 0xf) + (data & 0xf)) & 0xf0;
			processorFlags.carryFlag = ((registers->sp & 0xff) + (data & 0xff)) & 0xf00;
			return 12;
		}break;
		case (LD_nn_SP):
		{
			unsigned char n1 = GetData();
			unsigned char n2 = GetData();
			unsigned short val = combineChars(n2, n1);
			Emulator::GetInstance().GetMemoryManagerRef().memory[val] = registers->sp;
			return 20;
		}break;
#pragma endregion
#pragma region push and pop
		case (PUSH_AF):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->a;
			registers->sp--;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->f;
			registers->sp--;
			return 16;
		}break;
		case (PUSH_BC):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->b;
			registers->sp--;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->c;
			registers->sp--;
			return 16;
		}break;
		case (PUSH_DE):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->d;
			registers->sp--;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->e;
			registers->sp--;
			return 16;
		}break;
		case (PUSH_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->h;
			registers->sp--;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp] = registers->l;
			registers->sp--;
			return 16;
		}break;
		case (POP_AF):
		{
			registers->f = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			registers->a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			return 12;
		}break;
		case (POP_BC):
		{
			registers->c = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			registers->b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			return 12;
		}break;
		case (POP_DE):
		{
			registers->e = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			registers->d = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			return 12;
		}break;
		case (POP_HL):
		{
			registers->l = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			registers->h = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp];
			registers->sp++;
			return 12;
		}break;
#pragma endregion
#pragma region ALU arithmetic
		case(ADD_A_A):
		{
			alu_add(registers->a);
			return 4;
		}break;
		case(ADD_A_B):
		{
			alu_add(registers->b);
			return 4;
		}break;
		case(ADD_A_C):
		{
			alu_add(registers->c);
			return 4;
		}break;
		case(ADD_A_D):
		{
			alu_add(registers->d);
			return 4;
		}break;
		case(ADD_A_E):
		{
			alu_add(registers->e);
			return 4;
		}break;
		case(ADD_A_H):
		{
			alu_add(registers->h);
			return 4;
		}break;
		case(ADD_A_L):
		{
			alu_add(registers->l);
			return 4;
		}break;
		case(ADD_A_HL_VAL):
		{
			alu_add(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(ADD_A_n):
		{
			alu_add(GetData());
			return 8;
		}break;

		case(ADC_A_A):
		{
			alu_adc(registers->a);
			return 4;
		}break;
		case(ADC_A_B):
		{
			alu_adc(registers->b);
			return 4;
		}break;
		case(ADC_A_C):
		{
			alu_adc(registers->c);
			return 4;
		}break;
		case(ADC_A_D):
		{
			alu_adc(registers->d);
			return 4;
		}break;
		case(ADC_A_E):
		{
			alu_adc(registers->e);
			return 4;
		}break;
		case(ADC_A_H):
		{
			alu_adc(registers->h);
			return 4;
		}break;
		case(ADC_A_L):
		{
			alu_adc(registers->l);
			return 4;
		}break;
		case(ADC_A_HL_VAL):
		{
			alu_adc(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(ADC_A_n):
		{
			alu_adc(GetData());
			return 8;
		}break;

		case(SUB_A_A):
		{
			alu_sub(registers->a);
			return 4;
		}break;
		case(SUB_A_B):
		{
			alu_sub(registers->b);
			return 4;
		}break;
		case(SUB_A_C):
		{
			alu_sub(registers->c);
			return 4;
		}break;
		case(SUB_A_D):
		{
			alu_sub(registers->d);
			return 4;
		}break;
		case(SUB_A_E):
		{
			alu_sub(registers->e);
			return 4;
		}break;
		case(SUB_A_H):
		{
			alu_sub(registers->h);
			return 4;
		}break;
		case(SUB_A_L):
		{
			alu_sub(registers->l);
			return 4;
		}break;
		case(SUB_A_HL_VAL):
		{
			alu_sub(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(SUB_A_n):
		{
			alu_sub(GetData());
			return 8;
		}break;

		case(SBC_A_A):
		{
			alu_sbc(registers->a);
			return 4;
		}break;
		case(SBC_A_B):
		{
			alu_sbc(registers->b);
			return 4;
		}break;
		case(SBC_A_C):
		{
			alu_sbc(registers->c);
			return 4;
		}break;
		case(SBC_A_D):
		{
			alu_sbc(registers->d);
			return 4;
		}break;
		case(SBC_A_E):
		{
			alu_sbc(registers->e);
			return 4;
		}break;
		case(SBC_A_H):
		{
			alu_sbc(registers->h);
			return 4;
		}break;
		case(SBC_A_L):
		{
			alu_sbc(registers->l);
			return 4;
		}break;
		case(SBC_A_HL_VAL):
		{
			alu_sbc(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(SBC_A_n):
		{
			alu_sbc(GetData());
			return 8;
		}break;

#pragma endregion
#pragma region ALU logic
		case(AND_A):
		{
			alu_and(registers->a);
			return 4;
		}break;
		case(AND_B):
		{
			alu_and(registers->b);
			return 4;
		}break;
		case(AND_C):
		{
			alu_and(registers->c);
			return 4;
		}break;
		case(AND_D):
		{
			alu_and(registers->d);
			return 4;
		}break;
		case(AND_E):
		{
			alu_and(registers->e);
			return 4;
		}break;
		case(AND_H):
		{
			alu_and(registers->h);
			return 4;
		}break;
		case(AND_L):
		{
			alu_and(registers->l);
			return 4;
		}break;
		case(AND_HL_VAL):
		{
			alu_and(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(AND_n):
		{
			alu_and(GetData());
			return 8;
		}break;

		case(OR_A):
		{
			alu_or(registers->a);
			return 4;
		}break;
		case(OR_B):
		{
			alu_or(registers->b);
			return 4;
		}break;
		case(OR_C):
		{
			alu_or(registers->c);
			return 4;
		}break;
		case(OR_D):
		{
			alu_or(registers->d);
			return 4;
		}break;
		case(OR_E):
		{
			alu_or(registers->e);
			return 4;
		}break;
		case(OR_H):
		{
			alu_or(registers->h);
			return 4;
		}break;
		case(OR_L):
		{
			alu_or(registers->l);
			return 4;
		}break;
		case(OR_HL_VAL):
		{
			alu_or(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(OR_n):
		{
			alu_or(GetData());
			return 8;
		}break;

		case(XOR_A):
		{
			alu_xor(registers->a);
			return 4;
		}break;
		case(XOR_B):
		{
			alu_xor(registers->b);
			return 4;
		}break;
		case(XOR_C):
		{
			alu_xor(registers->c);
			return 4;
		}break;
		case(XOR_D):
		{
			alu_xor(registers->d);
			return 4;
		}break;
		case(XOR_E):
		{
			alu_xor(registers->e);
			return 4;
		}break;
		case(XOR_H):
		{
			alu_xor(registers->h);
			return 4;
		}break;
		case(XOR_L):
		{
			alu_xor(registers->l);
			return 4;
		}break;
		case(XOR_HL_VAL):
		{
			alu_xor(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(XOR_n):
		{
			alu_xor(GetData());
			return 8;
		}break;
		
		case(CP_A):
		{
			alu_cp(registers->a);
			return 4;
		}break;
		case(CP_B):
		{
			alu_cp(registers->b);
			return 4;
		}break;
		case(CP_C):
		{
			alu_cp(registers->c);
			return 4;
		}break;
		case(CP_D):
		{
			alu_cp(registers->d);
			return 4;
		}break;
		case(CP_E):
		{
			alu_cp(registers->e);
			return 4;
		}break;
		case(CP_H):
		{
			alu_cp(registers->h);
			return 4;
		}break;
		case(CP_L):
		{
			alu_cp(registers->l);
			return 4;
		}break;
		case(CP_HL_VAL):
		{
			alu_cp(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;
		case(CP_n):
		{
			alu_cp(GetData());
			return 8;
		}break;

#pragma endregion
#pragma region ALU increments

		case(INC_A):
		{
			registers->a = alu_inc(registers->a);
			return 4;
		}break;
		case(INC_B):
		{
			registers->b = alu_inc(registers->b);
			return 4;
		}break;
		case(INC_C):
		{
			registers->c = alu_inc(registers->c);
			return 4;
		}break;
		case(INC_D):
		{
			registers->d = alu_inc(registers->d);
			return 4;
		}break;
		case(INC_E):
		{
			registers->e = alu_inc(registers->e);
			return 4;
		}break;
		case(INC_H):
		{
			registers->h = alu_inc(registers->h);
			return 4;
		}break;
		case(INC_L):
		{
			registers->l = alu_inc(registers->l);
			return 4;
		}break;
		case(INC_HL_VAL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = alu_inc(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 12;
		}break;
		case(DEC_A):
		{
			registers->a = alu_dec(registers->a);
			return 4;
		}break;
		case(DEC_B):
		{
			registers->b = alu_dec(registers->b);
			return 4;
		}break;
		case(DEC_C):
		{
			registers->c = alu_dec(registers->c);
			return 4;
		}break;
		case(DEC_D):
		{
			registers->d = alu_dec(registers->d);
			return 4;
		}break;
		case(DEC_E):
		{
			registers->e = alu_dec(registers->e);
			return 4;
		}break;
		case(DEC_H):
		{
			registers->h = alu_dec(registers->h);
			return 4;
		}break;
		case(DEC_L):
		{
			registers->l = alu_dec(registers->l);
			return 4;
		}break;
		case(DEC_HL_VAL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = alu_dec(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 12;
		}break;
#pragma endregion
#pragma region ALU 16bit
		case(ADD_HL_BC):
		{
			alu_add16(registers->bc);
			return 8;
		}break;
		case(ADD_HL_DE):
		{
			alu_add16(registers->de);
			return 8;
		}break;
		case(ADD_HL_HL):
		{
			alu_add16(registers->hl);
			return 8;
		}break;
		case(ADD_HL_SP):
		{
			alu_add16(registers->sp);
			return 8;
		}break;
		case(ADD_SP_d):
		{
			unsigned char val = GetData();
			unsigned int result = registers->sp + val;
			processorFlags.zeroFlag = 0;
			processorFlags.subtractionFlag = 0;
			processorFlags.halfCarryFlag = (((registers->a & 0xfff) + (val & 0xfff)) & 0x1000);
			processorFlags.carryFlag = (result > 0xfff);
			registers->sp = (result & 0xffff);
			return 16;
		}break;
		case (INC_BC):
		{
			registers->bc = alu_inc16(registers->bc);
			return 8;
		}break;
		case (INC_DE):
		{
			registers->de = alu_inc16(registers->de);
			return 8;
		}break;
		case (INC_HL):
		{
			registers->hl = alu_inc16(registers->hl);
			return 8;
		}break;
		case (INC_SP):
		{
			registers->sp = alu_inc16(registers->sp);
			return 8;
		}break;
		case (DEC_BC):
		{
			registers->bc = alu_dec16(registers->bc);
			return 8;
		}break;
		case (DEC_DE):
		{
			registers->de = alu_dec16(registers->de);
			return 8;
		}break;
		case (DEC_HL):
		{
			registers->hl = alu_dec16(registers->hl);
			return 8;
		}break;
		case (DEC_SP):
		{
			registers->sp = alu_dec16(registers->sp);
			return 8;
		}break;
#pragma endregion
#pragma region misc
		case(DAA):
		{
			daa();
			return 4;
		}break;
		case(CPL):
		{
			registers->a = ~registers->a;
			processorFlags.subtractionFlag = 1;
			processorFlags.halfCarryFlag = 1;
			return 4;
		}break;
		case(CCF):
		{
			processorFlags.subtractionFlag = 0;
			processorFlags.halfCarryFlag = 0;
			processorFlags.carryFlag = !processorFlags.carryFlag;
			return 4;
		}break;
		case(SCF):
		{
			processorFlags.subtractionFlag = 0;
			processorFlags.halfCarryFlag = 0;
			processorFlags.carryFlag = 1;
			return 4;
		}break;
		case(NOP):
		{
			return 4;
		}break;
		case(HALT):
		{
			processorFlags.halt = 1;
			registers->pc--;
			return 4;
		}break;
		case(STOP):
		{
			processorFlags.halt = 1;
			return 4;
		}break;
		case(DI):
		{
			processorFlags.interruptMasterEnable = 0;
			return 4;
		}break;
		case(EI):
		{
			processorFlags.interruptMasterEnable = 1;
			return 4;
		}break;
#pragma endregion
#pragma region rotates
		case(RLC_A):
		{
			registers->a = rlc(registers->a, true);
			return 4;
		}break;
		case(RL_A):
		{
			registers->a = rl(registers->a, true);
			return 4;
		}break;
		case(RRC_A):
		{
			registers->a = rrc(registers->a, true);
			return 4;
		}break;
		case(RR_A):
		{
			registers->a = rr(registers->a, true);
			return 4;
		}break;
#pragma endregion
#pragma region jumps calls and retunrs
		case (JP_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			registers->pc = comb;
			return 12;
		}break;
		case (JP_NZ_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.zeroFlag == 0)
				registers->pc = comb;
			return 12;
		}break;
		case (JP_Z_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.zeroFlag == 1)
				registers->pc = comb;
			return 12;
		}break;
		case (JP_NC_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.carryFlag == 0)
				registers->pc = comb;
			return 12;
		}break;
		case (JP_C_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.carryFlag == 1)
				registers->pc = comb;
			return 12;
		}break;
		case (JP_HL):
		{
			registers->pc = registers->hl;
			return 4;
		}break;
		case (JR_n):
		{
			int a = (char)GetData();
			registers->pc = registers->pc + a;
			return 8;
		}break;
		case (JR_NZ_n):
		{
			int a = (char)GetData();
			if (processorFlags.zeroFlag == 0)
				registers->pc = registers->pc + a;
			return 8;
		}break;
		case (JR_Z_n):
		{
			int a = (char)GetData();
			if (processorFlags.zeroFlag == 1)
				registers->pc = registers->pc + a;
			return 8;
		}break;
		case (JR_NC_n):
		{
			int a = (char)GetData();
			if (processorFlags.carryFlag == 0)
				registers->pc = registers->pc + a;
			return 8;
		}break;
		case (JR_C_n):
		{
			int a = (char)GetData();
			if (processorFlags.carryFlag == 1)
				registers->pc = registers->pc + a;
			return 8;
		}break;

		case (CALL_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = comb;
			return 12;
		}break;
		case (CALL_NZ_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.zeroFlag == 0) {
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
				registers->pc = comb;
			}
			return 12;
		}break;
		case (CALL_Z_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.zeroFlag == 1) {
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
				registers->pc = comb;
			}
			return 12;
		}break;
		case (CALL_NC_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.carryFlag == 0) {
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
				registers->pc = comb;
			}
			return 12;
		}break;
		case (CALL_C_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			if (processorFlags.carryFlag == 1) {
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
				Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
				registers->pc = comb;
			}
			return 12;
		}break;

		case (RST_0):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0000;
			return 32;
		}break;
		case (RST_8):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0008;
			return 32;
		}break;
		case (RST_10):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0010;
			return 32;
		}break;
		case (RST_18):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0018;
			return 32;
		}break;
		case (RST_20):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0020;
			return 32;
		}break;
		case (RST_28):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0028;
			return 32;
		}break;
		case (RST_30):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0030;
			return 32;
		}break;
		case (RST_38):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = registers->pc & 0x00FF;
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp--] = (registers->pc >> 8) & 0x00FF;
			registers->pc = 0x0038;
			return 32;
		}break;

		case (RET):
		{
			unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
			unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
			unsigned short comb = combineChars(b, a);
			registers->pc = comb;
			return 8;
		}break;
		case (RET_NZ):
		{
			if (processorFlags.zeroFlag == 0)
			{
				unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned short comb = combineChars(b, a);
				registers->pc = comb;
			}
			return 8;
		}break;
		case (RET_Z):
		{
			if (processorFlags.zeroFlag == 1)
			{
				unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned short comb = combineChars(b, a);
				registers->pc = comb;
			}
			return 8;
		}break;
		case (RET_NC):
		{
			if (processorFlags.carryFlag == 0)
			{
				unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned short comb = combineChars(b, a);
				registers->pc = comb;
			}
			return 8;
		}break;
		case (RET_C):
		{
			if (processorFlags.carryFlag == 1)
			{
				unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
				unsigned short comb = combineChars(b, a);
				registers->pc = comb;
			}
			return 8;
		}break;
		case(RETI):
		{
			unsigned char a = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
			unsigned char b = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->sp++];
			unsigned short comb = combineChars(b, a);
			registers->pc = comb;
			processorFlags.interruptMasterEnable = 1;
			return 8;
		}break;
#pragma endregion

		case(PREFIX_CB):
		{
			return ProcessCBPrefixInstruction();
		}break;
		default:
		{
			throw std::invalid_argument(std::format("[ERROR] Unimplemented instruction: '{:0>2X}' at position '{:0>4X}'", inst, registers->pc));
		} break;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
		//throw e.what();
	}
}
