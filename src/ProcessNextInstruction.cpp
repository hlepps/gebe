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
		std::cout << "PC: " << ToHex(registers->pc) << " | Current instruction:" << ToHex(inst) << std::endl;
		registers->pc++;
		switch (inst)
		{
			// no instruction
		case(NOP):
		{
			return 4;
		}break;
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
#pragma region ALU
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
			return 4;
		}break;
		case(ADD_A_n):
		{
			alu_add(GetData());
			return 4;
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
			return 4;
		}break;
		case(ADC_A_n):
		{
			alu_adc(GetData());
			return 4;
		}break;

#pragma endregion

		case (JP_nn):
		{
			unsigned char a = GetData();
			unsigned char b = GetData();
			unsigned short comb = combineChars(b, a);
			registers->pc = comb;
			return 12;
		} break;
		default:
		{
			throw std::invalid_argument(std::format("[ERROR] Unimplemented instruction: '{:0>2X}' at position '{:0>4X}'", inst, registers->pc));
		} break;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
		throw e.what();
	}
}

void InstructionProcessor::alu_add(unsigned char val)
{
	short result = registers->a + val;
	// found:
	//processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.zeroFlag = (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) + (val & 0xf)) & 0x10);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}

void InstructionProcessor::alu_adc(unsigned char val)
{
	unsigned char carry = processorFlags.carryFlag;
	short result = registers->a + val + carry;
	// found:
	//processorFlags.zeroFlag = ((result & 0xff) == 0);
	processorFlags.zeroFlag = (result == 0);
	processorFlags.subtractionFlag = 0;
	processorFlags.halfCarryFlag = (((registers->a & 0xf) + (val & 0xf) + (carry & 0xf)) & 0x10);
	processorFlags.carryFlag = (result > 0xff);
	registers->a = (result & 0xff);
}