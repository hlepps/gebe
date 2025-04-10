#include "InstructionProcessor.h"

#include <exception>
#include <format>
#include <string>
#include <iostream>
#include "Emulator.h"
#include "OPCodeTable.h"
#include "Useful.h"
#include "Offsets.h"

int InstructionProcessor::ProcessCBPrefixInstruction()
{
	try {

		unsigned char inst = Emulator::GetInstance().GetMemoryManagerRef().memory[registers->pc];
		std::cout << "PC: " << ToHex(registers->pc) << " | Current instruction: CB " << ToHex(inst) << std::endl;
		registers->pc++;
		switch (inst)
		{
#pragma region rotation
		case(CB_RLCA):
		{
			registers->a = rlc(registers->a,false);
			return 8;
		}break;
		case(CB_RLCB):
		{
			registers->b = rlc(registers->b,false);
			return 8;
		}break;
		case(CB_RLCC):
		{
			registers->c = rlc(registers->c,false);
			return 8;
		}break;
		case(CB_RLCD):
		{
			registers->d = rlc(registers->d,false);
			return 8;
		}break;
		case(CB_RLCE):
		{
			registers->e = rlc(registers->e, false);
			return 8;
		}break;
		case(CB_RLCH):
		{
			registers->h = rlc(registers->h,false);
			return 8;
		}break;
		case(CB_RLCL):
		{
			registers->l = rlc(registers->l,false);
			return 8;
		}break;
		case(CB_RLC_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = rlc(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl],false);
			return 16;
		}break;
		case(CB_RLA):
		{
			registers->a = rl(registers->a,false);
			return 8;
		}break;
		case(CB_RLB):
		{
			registers->b = rl(registers->b,false);
			return 8;
		}break;
		case(CB_RLC):
		{
			registers->c = rl(registers->c,false);
			return 8;
		}break;
		case(CB_RLD):
		{
			registers->d = rl(registers->d,false);
			return 8;
		}break;
		case(CB_RLE):
		{
			registers->e = rl(registers->e, false);
			return 8;
		}break;
		case(CB_RLH):
		{
			registers->h = rl(registers->h,false);
			return 8;
		}break;
		case(CB_RLL):
		{
			registers->l = rl(registers->l,false);
			return 8;
		}break;
		case(CB_RL_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = rl(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl],false);
			return 16;
		}break;

		case(CB_RRA):
		{
			registers->a = rr(registers->a, false);
			return 8;
		}break;
		case(CB_RRB):
		{
			registers->b = rr(registers->b, false);
			return 8;
		}break;
		case(CB_RRC):
		{
			registers->c = rr(registers->c, false);
			return 8;
		}break;
		case(CB_RRD):
		{
			registers->d = rr(registers->d, false);
			return 8;
		}break;
		case(CB_RRE):
		{
			registers->e = rr(registers->e, false);
			return 8;
		}break;
		case(CB_RRH):
		{
			registers->h = rr(registers->h, false);
			return 8;
		}break;
		case(CB_RRL):
		{
			registers->l = rr(registers->l, false);
			return 8;
		}break;
		case(CB_RR_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = rr(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl], false);
			return 16;
		}break;

		case(CB_RRCA):
		{
			registers->a = rrc(registers->a, false);
			return 8;
		}break;
		case(CB_RRCB):
		{
			registers->b = rrc(registers->b, false);
			return 8;
		}break;
		case(CB_RRCC):
		{
			registers->c = rrc(registers->c, false);
			return 8;
		}break;
		case(CB_RRCD):
		{
			registers->d = rrc(registers->d, false);
			return 8;
		}break;
		case(CB_RRCE):
		{
			registers->e = rrc(registers->e, false);
			return 8;
		}break;
		case(CB_RRCH):
		{
			registers->h = rrc(registers->h, false);
			return 8;
		}break;
		case(CB_RRCL):
		{
			registers->l = rrc(registers->l, false);
			return 8;
		}break;
		case(CB_RRC_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = rrc(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl], false);
			return 16;
		}break;
#pragma endregion
#pragma region shift

		case(CB_SLAA):
		{
			registers->a = sla(registers->a);
			return 8;
		}break;
		case(CB_SLAB):
		{
			registers->b = sla(registers->b);
			return 8;
		}break;
		case(CB_SLAC):
		{
			registers->c = sla(registers->c);
			return 8;
		}break;
		case(CB_SLAD):
		{
			registers->d = sla(registers->d);
			return 8;
		}break;
		case(CB_SLAE):
		{
			registers->e = sla(registers->e);
			return 8;
		}break;
		case(CB_SLAH):
		{
			registers->h = sla(registers->h);
			return 8;
		}break;
		case(CB_SLAL):
		{
			registers->l = sla(registers->l);
			return 8;
		}break;
		case(CB_SLA_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = sla(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SRAA):
		{
			registers->a = sra(registers->a);
			return 8;
		}break;
		case(CB_SRAB):
		{
			registers->b = sra(registers->b);
			return 8;
		}break;
		case(CB_SRAC):
		{
			registers->c = sra(registers->c);
			return 8;
		}break;
		case(CB_SRAD):
		{
			registers->d = sra(registers->d);
			return 8;
		}break;
		case(CB_SRAE):
		{
			registers->e = sra(registers->e);
			return 8;
		}break;
		case(CB_SRAH):
		{
			registers->h = sra(registers->h);
			return 8;
		}break;
		case(CB_SRAL):
		{
			registers->l = sra(registers->l);
			return 8;
		}break;
		case(CB_SRA_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = sla(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;
		case(CB_SRLA):
		{
			registers->a = srl(registers->a);
			return 8;
		}break;
		case(CB_SRLB):
		{
			registers->b = srl(registers->b);
			return 8;
		}break;
		case(CB_SRLC):
		{
			registers->c = srl(registers->c);
			return 8;
		}break;
		case(CB_SRLD):
		{
			registers->d = srl(registers->d);
			return 8;
		}break;
		case(CB_SRLE):
		{
			registers->e = srl(registers->e);
			return 8;
		}break;
		case(CB_SRLH):
		{
			registers->h = srl(registers->h);
			return 8;
		}break;
		case(CB_SRLL):
		{
			registers->l = srl(registers->l);
			return 8;
		}break;
		case(CB_SRL_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = srl(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

#pragma endregion
#pragma region bit check

		case(CB_BIT0A):
		{
			bit(0, registers->a);
			return 8;
		}break;
		case(CB_BIT0B):
		{
			bit(0, registers->b);
			return 8;
		}break;
		case(CB_BIT0C):
		{
			bit(0, registers->c);
			return 8;
		}break;
		case(CB_BIT0D):
		{
			bit(0, registers->d);
			return 8;
		}break;
		case(CB_BIT0E):
		{
			bit(0, registers->e);
			return 8;
		}break;
		case(CB_BIT0H):
		{
			bit(0, registers->h);
			return 8;
		}break;
		case(CB_BIT0L):
		{
			bit(0, registers->l);
			return 8;
		}break;
		case(CB_BIT0_HL):
		{
			bit(0, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT1A):
		{
			bit(1, registers->a);
			return 8;
		}break;
		case(CB_BIT1B):
		{
			bit(1, registers->b);
			return 8;
		}break;
		case(CB_BIT1C):
		{
			bit(1, registers->c);
			return 8;
		}break;
		case(CB_BIT1D):
		{
			bit(1, registers->d);
			return 8;
		}break;
		case(CB_BIT1E):
		{
			bit(1, registers->e);
			return 8;
		}break;
		case(CB_BIT1H):
		{
			bit(1, registers->h);
			return 8;
		}break;
		case(CB_BIT1L):
		{
			bit(1, registers->l);
			return 8;
		}break;
		case(CB_BIT1_HL):
		{
			bit(1, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT2A):
		{
			bit(2, registers->a);
			return 8;
		}break;
		case(CB_BIT2B):
		{
			bit(2, registers->b);
			return 8;
		}break;
		case(CB_BIT2C):
		{
			bit(2, registers->c);
			return 8;
		}break;
		case(CB_BIT2D):
		{
			bit(2, registers->d);
			return 8;
		}break;
		case(CB_BIT2E):
		{
			bit(2, registers->e);
			return 8;
		}break;
		case(CB_BIT2H):
		{
			bit(2, registers->h);
			return 8;
		}break;
		case(CB_BIT2L):
		{
			bit(2, registers->l);
			return 8;
		}break;
		case(CB_BIT2_HL):
		{
			bit(2, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT3A):
		{
			bit(3, registers->a);
			return 8;
		}break;
		case(CB_BIT3B):
		{
			bit(3, registers->b);
			return 8;
		}break;
		case(CB_BIT3C):
		{
			bit(3, registers->c);
			return 8;
		}break;
		case(CB_BIT3D):
		{
			bit(3, registers->d);
			return 8;
		}break;
		case(CB_BIT3E):
		{
			bit(3, registers->e);
			return 8;
		}break;
		case(CB_BIT3H):
		{
			bit(3, registers->h);
			return 8;
		}break;
		case(CB_BIT3L):
		{
			bit(3, registers->l);
			return 8;
		}break;
		case(CB_BIT3_HL):
		{
			bit(3, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT4A):
		{
			bit(4, registers->a);
			return 8;
		}break;
		case(CB_BIT4B):
		{
			bit(4, registers->b);
			return 8;
		}break;
		case(CB_BIT4C):
		{
			bit(4, registers->c);
			return 8;
		}break;
		case(CB_BIT4D):
		{
			bit(4, registers->d);
			return 8;
		}break;
		case(CB_BIT4E):
		{
			bit(4, registers->e);
			return 8;
		}break;
		case(CB_BIT4H):
		{
			bit(4, registers->h);
			return 8;
		}break;
		case(CB_BIT4L):
		{
			bit(4, registers->l);
			return 8;
		}break;
		case(CB_BIT4_HL):
		{
			bit(4, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT5A):
		{
			bit(5, registers->a);
			return 8;
		}break;
		case(CB_BIT5B):
		{
			bit(5, registers->b);
			return 8;
		}break;
		case(CB_BIT5C):
		{
			bit(5, registers->c);
			return 8;
		}break;
		case(CB_BIT5D):
		{
			bit(5, registers->d);
			return 8;
		}break;
		case(CB_BIT5E):
		{
			bit(5, registers->e);
			return 8;
		}break;
		case(CB_BIT5H):
		{
			bit(5, registers->h);
			return 8;
		}break;
		case(CB_BIT5L):
		{
			bit(5, registers->l);
			return 8;
		}break;
		case(CB_BIT5_HL):
		{
			bit(5, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT6A):
		{
			bit(6, registers->a);
			return 8;
		}break;
		case(CB_BIT6B):
		{
			bit(6, registers->b);
			return 8;
		}break;
		case(CB_BIT6C):
		{
			bit(6, registers->c);
			return 8;
		}break;
		case(CB_BIT6D):
		{
			bit(6, registers->d);
			return 8;
		}break;
		case(CB_BIT6E):
		{
			bit(6, registers->e);
			return 8;
		}break;
		case(CB_BIT6H):
		{
			bit(6, registers->h);
			return 8;
		}break;
		case(CB_BIT6L):
		{
			bit(6, registers->l);
			return 8;
		}break;
		case(CB_BIT6_HL):
		{
			bit(6, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_BIT7A):
		{
			bit(7, registers->a);
			return 8;
		}break;
		case(CB_BIT7B):
		{
			bit(7, registers->b);
			return 8;
		}break;
		case(CB_BIT7C):
		{
			bit(7, registers->c);
			return 8;
		}break;
		case(CB_BIT7D):
		{
			bit(7, registers->d);
			return 8;
		}break;
		case(CB_BIT7E):
		{
			bit(7, registers->e);
			return 8;
		}break;
		case(CB_BIT7H):
		{
			bit(7, registers->h);
			return 8;
		}break;
		case(CB_BIT7L):
		{
			bit(7, registers->l);
			return 8;
		}break;
		case(CB_BIT7_HL):
		{
			bit(7, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

#pragma endregion	
#pragma region bit set

		case(CB_SET0A):
		{
			registers->a = set(0, registers->a);
			return 8;
		}break;
		case(CB_SET0B):
		{
			registers->b = set(0, registers->b);
			return 8;
		}break;
		case(CB_SET0C):
		{
			registers->c = set(0, registers->c);
			return 8;
		}break;
		case(CB_SET0D):
		{
			registers->d = set(0, registers->d);
			return 8;
		}break;
		case(CB_SET0E):
		{
			registers->e = set(0, registers->e);
			return 8;
		}break;
		case(CB_SET0H):
		{
			registers->h = set(0, registers->h);
			return 8;
		}break;
		case(CB_SET0L):
		{
			registers->l = set(0, registers->l);
			return 8;
		}break;
		case(CB_SET0_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(0, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET1A):
		{
			registers->a = set(1, registers->a);
			return 8;
		}break;
		case(CB_SET1B):
		{
			registers->b = set(1, registers->b);
			return 8;
		}break;
		case(CB_SET1C):
		{
			registers->c = set(1, registers->c);
			return 8;
		}break;
		case(CB_SET1D):
		{
			registers->d = set(1, registers->d);
			return 8;
		}break;
		case(CB_SET1E):
		{
			registers->e = set(1, registers->e);
			return 8;
		}break;
		case(CB_SET1H):
		{
			registers->h = set(1, registers->h);
			return 8;
		}break;
		case(CB_SET1L):
		{
			registers->l = set(1, registers->l);
			return 8;
		}break;
		case(CB_SET1_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(1, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET2A):
		{
			registers->a = set(2, registers->a);
			return 8;
		}break;
		case(CB_SET2B):
		{
			registers->b = set(2, registers->b);
			return 8;
		}break;
		case(CB_SET2C):
		{
			registers->c = set(2, registers->c);
			return 8;
		}break;
		case(CB_SET2D):
		{
			registers->d = set(2, registers->d);
			return 8;
		}break;
		case(CB_SET2E):
		{
			registers->e = set(2, registers->e);
			return 8;
		}break;
		case(CB_SET2H):
		{
			registers->h = set(2, registers->h);
			return 8;
		}break;
		case(CB_SET2L):
		{
			registers->l = set(2, registers->l);
			return 8;
		}break;
		case(CB_SET2_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(2, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET3A):
		{
			registers->a = set(3, registers->a);
			return 8;
		}break;
		case(CB_SET3B):
		{
			registers->b = set(3, registers->b);
			return 8;
		}break;
		case(CB_SET3C):
		{
			registers->c = set(3, registers->c);
			return 8;
		}break;
		case(CB_SET3D):
		{
			registers->d = set(3, registers->d);
			return 8;
		}break;
		case(CB_SET3E):
		{
			registers->e = set(3, registers->e);
			return 8;
		}break;
		case(CB_SET3H):
		{
			registers->h = set(3, registers->h);
			return 8;
		}break;
		case(CB_SET3L):
		{
			registers->l = set(3, registers->l);
			return 8;
		}break;
		case(CB_SET3_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(3, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET4A):
		{
			registers->a = set(4, registers->a);
			return 8;
		}break;
		case(CB_SET4B):
		{
			registers->b = set(4, registers->b);
			return 8;
		}break;
		case(CB_SET4C):
		{
			registers->c = set(4, registers->c);
			return 8;
		}break;
		case(CB_SET4D):
		{
			registers->d = set(4, registers->d);
			return 8;
		}break;
		case(CB_SET4E):
		{
			registers->e = set(4, registers->e);
			return 8;
		}break;
		case(CB_SET4H):
		{
			registers->h = set(4, registers->h);
			return 8;
		}break;
		case(CB_SET4L):
		{
			registers->l = set(4, registers->l);
			return 8;
		}break;
		case(CB_SET4_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(4, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET5A):
		{
			registers->a = set(5, registers->a);
			return 8;
		}break;
		case(CB_SET5B):
		{
			registers->b = set(5, registers->b);
			return 8;
		}break;
		case(CB_SET5C):
		{
			registers->c = set(5, registers->c);
			return 8;
		}break;
		case(CB_SET5D):
		{
			registers->d = set(5, registers->d);
			return 8;
		}break;
		case(CB_SET5E):
		{
			registers->e = set(5, registers->e);
			return 8;
		}break;
		case(CB_SET5H):
		{
			registers->h = set(5, registers->h);
			return 8;
		}break;
		case(CB_SET5L):
		{
			registers->l = set(5, registers->l);
			return 8;
		}break;
		case(CB_SET5_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(5, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET6A):
		{
			registers->a = set(6, registers->a);
			return 8;
		}break;
		case(CB_SET6B):
		{
			registers->b = set(6, registers->b);
			return 8;
		}break;
		case(CB_SET6C):
		{
			registers->c = set(6, registers->c);
			return 8;
		}break;
		case(CB_SET6D):
		{
			registers->d = set(6, registers->d);
			return 8;
		}break;
		case(CB_SET6E):
		{
			registers->e = set(6, registers->e);
			return 8;
		}break;
		case(CB_SET6H):
		{
			registers->h = set(6, registers->h);
			return 8;
		}break;
		case(CB_SET6L):
		{
			registers->l = set(6, registers->l);
			return 8;
		}break;
		case(CB_SET6_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(6, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_SET7A):
		{
			registers->a = set(7, registers->a);
			return 8;
		}break;
		case(CB_SET7B):
		{
			registers->b = set(7, registers->b);
			return 8;
		}break;
		case(CB_SET7C):
		{
			registers->c = set(7, registers->c);
			return 8;
		}break;
		case(CB_SET7D):
		{
			registers->d = set(7, registers->d);
			return 8;
		}break;
		case(CB_SET7E):
		{
			registers->e = set(7, registers->e);
			return 8;
		}break;
		case(CB_SET7H):
		{
			registers->h = set(7, registers->h);
			return 8;
		}break;
		case(CB_SET7L):
		{
			registers->l = set(7, registers->l);
			return 8;
		}break;
		case(CB_SET7_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = set(7, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

#pragma endregion
#pragma region bit reset

		case(CB_RES0A):
		{
			registers->a = res(0, registers->a);
			return 8;
		}break;
		case(CB_RES0B):
		{
			registers->b = res(0, registers->b);
			return 8;
		}break;
		case(CB_RES0C):
		{
			registers->c = res(0, registers->c);
			return 8;
		}break;
		case(CB_RES0D):
		{
			registers->d = res(0, registers->d);
			return 8;
		}break;
		case(CB_RES0E):
		{
			registers->e = res(0, registers->e);
			return 8;
		}break;
		case(CB_RES0H):
		{
			registers->h = res(0, registers->h);
			return 8;
		}break;
		case(CB_RES0L):
		{
			registers->l = res(0, registers->l);
			return 8;
		}break;
		case(CB_RES0_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(0, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES1A):
		{
			registers->a = res(1, registers->a);
			return 8;
		}break;
		case(CB_RES1B):
		{
			registers->b = res(1, registers->b);
			return 8;
		}break;
		case(CB_RES1C):
		{
			registers->c = res(1, registers->c);
			return 8;
		}break;
		case(CB_RES1D):
		{
			registers->d = res(1, registers->d);
			return 8;
		}break;
		case(CB_RES1E):
		{
			registers->e = res(1, registers->e);
			return 8;
		}break;
		case(CB_RES1H):
		{
			registers->h = res(1, registers->h);
			return 8;
		}break;
		case(CB_RES1L):
		{
			registers->l = res(1, registers->l);
			return 8;
		}break;
		case(CB_RES1_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(1, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES2A):
		{
			registers->a = res(2, registers->a);
			return 8;
		}break;
		case(CB_RES2B):
		{
			registers->b = res(2, registers->b);
			return 8;
		}break;
		case(CB_RES2C):
		{
			registers->c = res(2, registers->c);
			return 8;
		}break;
		case(CB_RES2D):
		{
			registers->d = res(2, registers->d);
			return 8;
		}break;
		case(CB_RES2E):
		{
			registers->e = res(2, registers->e);
			return 8;
		}break;
		case(CB_RES2H):
		{
			registers->h = res(2, registers->h);
			return 8;
		}break;
		case(CB_RES2L):
		{
			registers->l = res(2, registers->l);
			return 8;
		}break;
		case(CB_RES2_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(2, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES3A):
		{
			registers->a = res(3, registers->a);
			return 8;
		}break;
		case(CB_RES3B):
		{
			registers->b = res(3, registers->b);
			return 8;
		}break;
		case(CB_RES3C):
		{
			registers->c = res(3, registers->c);
			return 8;
		}break;
		case(CB_RES3D):
		{
			registers->d = res(3, registers->d);
			return 8;
		}break;
		case(CB_RES3E):
		{
			registers->e = res(3, registers->e);
			return 8;
		}break;
		case(CB_RES3H):
		{
			registers->h = res(3, registers->h);
			return 8;
		}break;
		case(CB_RES3L):
		{
			registers->l = res(3, registers->l);
			return 8;
		}break;
		case(CB_RES3_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(3, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES4A):
		{
			registers->a = res(4, registers->a);
			return 8;
		}break;
		case(CB_RES4B):
		{
			registers->b = res(4, registers->b);
			return 8;
		}break;
		case(CB_RES4C):
		{
			registers->c = res(4, registers->c);
			return 8;
		}break;
		case(CB_RES4D):
		{
			registers->d = res(4, registers->d);
			return 8;
		}break;
		case(CB_RES4E):
		{
			registers->e = res(4, registers->e);
			return 8;
		}break;
		case(CB_RES4H):
		{
			registers->h = res(4, registers->h);
			return 8;
		}break;
		case(CB_RES4L):
		{
			registers->l = res(4, registers->l);
			return 8;
		}break;
		case(CB_RES4_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(4, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES5A):
		{
			registers->a = res(5, registers->a);
			return 8;
		}break;
		case(CB_RES5B):
		{
			registers->b = res(5, registers->b);
			return 8;
		}break;
		case(CB_RES5C):
		{
			registers->c = res(5, registers->c);
			return 8;
		}break;
		case(CB_RES5D):
		{
			registers->d = res(5, registers->d);
			return 8;
		}break;
		case(CB_RES5E):
		{
			registers->e = res(5, registers->e);
			return 8;
		}break;
		case(CB_RES5H):
		{
			registers->h = res(5, registers->h);
			return 8;
		}break;
		case(CB_RES5L):
		{
			registers->l = res(5, registers->l);
			return 8;
		}break;
		case(CB_RES5_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(5, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES6A):
		{
			registers->a = res(6, registers->a);
			return 8;
		}break;
		case(CB_RES6B):
		{
			registers->b = res(6, registers->b);
			return 8;
		}break;
		case(CB_RES6C):
		{
			registers->c = res(6, registers->c);
			return 8;
		}break;
		case(CB_RES6D):
		{
			registers->d = res(6, registers->d);
			return 8;
		}break;
		case(CB_RES6E):
		{
			registers->e = res(6, registers->e);
			return 8;
		}break;
		case(CB_RES6H):
		{
			registers->h = res(6, registers->h);
			return 8;
		}break;
		case(CB_RES6L):
		{
			registers->l = res(6, registers->l);
			return 8;
		}break;
		case(CB_RES6_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(6, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

		case(CB_RES7A):
		{
			registers->a = res(7, registers->a);
			return 8;
		}break;
		case(CB_RES7B):
		{
			registers->b = res(7, registers->b);
			return 8;
		}break;
		case(CB_RES7C):
		{
			registers->c = res(7, registers->c);
			return 8;
		}break;
		case(CB_RES7D):
		{
			registers->d = res(7, registers->d);
			return 8;
		}break;
		case(CB_RES7E):
		{
			registers->e = res(7, registers->e);
			return 8;
		}break;
		case(CB_RES7H):
		{
			registers->h = res(7, registers->h);
			return 8;
		}break;
		case(CB_RES7L):
		{
			registers->l = res(7, registers->l);
			return 8;
		}break;
		case(CB_RES7_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = res(7, Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 16;
		}break;

#pragma endregion
#pragma region swap
		case(CB_SWAPA):
		{
			registers->a = swap(registers->a);
			return 8;
		}break;
		case(CB_SWAPB):
		{
			registers->b = swap(registers->b);
			return 8;
		}break;
		case(CB_SWAPC):
		{
			registers->c = swap(registers->c);
			return 8;
		}break;
		case(CB_SWAPD):
		{
			registers->d = swap(registers->d);
			return 8;
		}break;
		case(CB_SWAPE):
		{
			registers->e = swap(registers->e);
			return 8;
		}break;
		case(CB_SWAPH):
		{
			registers->h = swap(registers->h);
			return 8;
		}break;
		case(CB_SWAPL):
		{
			registers->l = swap(registers->l);
			return 8;
		}break;
		case(CB_SWAP_HL):
		{
			Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl] = swap(Emulator::GetInstance().GetMemoryManagerRef().memory[registers->hl]);
			return 8;
		}break;

#pragma endregion
		
		default:
		{
			throw std::invalid_argument(std::format("[ERROR] Unimplemented CB Prefix instruction: 'CB {:0>2X}' at position '{:0>4X}'", inst, registers->pc));
		} break;
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
		throw e;
	}
}