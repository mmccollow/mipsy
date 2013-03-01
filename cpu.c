#include "global.h"
#include "mem.h"

const u32 zero = 0; // zero register
u32 v0, v1; // return value registers
u32 a0, a1, a2, a3; // procedure argument registers
u32 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9; // temp registers
u32 s0, s1, s2, s3, s4, s5, s6, s7; // saved registers
u32 gp, sp, fp, ra; // global, stack, and frame pointers; return addr register
u32 pc; // program counter

/**
 * Read next instruction from memory
 */
u32 fetch() {
	return mainMemory[pc++];
}

/**
 * Resets the CPU and memory
 */
u32 reset() {
	v0 = 0;
	v1 = 0;
	a0 = 0;
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = 0;
	t3 = 0;
	t4 = 0;
	t5 = 0;
	t6 = 0;
	t7 = 0;
	t8 = 0;
	t9 = 0;
	s0 = 0;
	s1 = 0;
	s2 = 0;
	s3 = 0;
	s4 = 0;
	s5 = 0;
	s6 = 0;
	s7 = 0;
	gp = 0;
	sp = 0;
	fp = 0;
	ra = 0;
	pc = 0;
	int i;
	for (i = 0; i < sizeof(mainMemory); i++) {
		mainMemory[i] = 0;
	}
}

int main() {
}

/**
 * MIPS instruction set
 */
void add(rd, rs, rt) {
	rd = rs + rt;
}

void addi(rd, rs, n) {
	rd = rs + n;
}

void sub(rd, rs, rt) {
	rd = rs - rt;
}

void lw(rd, address) {
	rd = mainMemory[address];
}

void sw(rs, address) {
	mainMemory[address] = rs;
}

void and(rd, rs, rt) {
	rd = rs & rt;
}

void or(rd, rs, rt) {
	rd = rs | rt;
}

void nor(rd, rs, rt) {
	rd = ~(rs|rt);
}

void andi(rd, rs, n) {
	rd = rs & n;
}

void ori(rd, rs, n) {
	rd = rs | n;
}

void sll(rd, rs, n) {
	rd = rs << n;
}

void srl(rd, rs, n) {
	rd = rs >> n;
}

void beq(rs, rt, address) {
	if (rs == rt) {
		pc = address;
	}
}

void bne(rs, rt, address) {
	if (rs != rt) {
		pc = address;
	}
}

void slt(rd, rs, rt) {
	if (rs < rt) {
		rd = 1;
	}
}

void j(address) {
	pc = address;
}

void jr(rs) {
	pc = rs;
}

void jal(address) {
	ra = pc;
	pc = address;
}

