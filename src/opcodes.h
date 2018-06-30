#include <stdint.h>
#include <stdio.h>

// Stop and Arithmetic
const uint8_t STOP = 0x00;
const uint8_t ADD = 0x01;
const uint8_t MUL = 0x02;
const uint8_t SUB = 0x03;
const uint8_t DIV = 0x04;
const uint8_t SDIV = 0x05;
const uint8_t MOD = 0x06;
const uint8_t SMOD = 0x07;
const uint8_t ADDMOD = 0x08;
const uint8_t MULMOD = 0x09;
const uint8_t EXP = 0x0a;
const uint8_t SIGNEXTEND = 0x0b;

// Comparison and Bitwise Logic
const uint8_t LT = 0x10;
const uint8_t GT = 0x11;
const uint8_t SLT = 0x12;
const uint8_t SGT = 0x13;
const uint8_t EQ = 0x14;
const uint8_t ISZERO = 0x15;
const uint8_t AND = 0x16;
const uint8_t OR = 0x17;
const uint8_t XOR = 0x18;
const uint8_t NOT = 0x19;
const uint8_t BYTE = 0x1a;

// Sha3
const uint8_t SHA3 = 0x20;

// Environment Information
const uint8_t ADDRESS = 0x30;
const uint8_t BALANCE = 0x31;
const uint8_t ORIGIN = 0x32;
const uint8_t CALLER = 0x33;
const uint8_t CALLVALUE = 0x34;
const uint8_t CALLDATALOAD = 0x35;
const uint8_t CALLDATASIZE = 0x36;
const uint8_t CALLDATACOPY = 0x37;
const uint8_t CODESIZE = 0x38;
const uint8_t CODECOPY = 0x39;
const uint8_t GASPRICE = 0x3a;
const uint8_t EXTCODESIZE = 0x3b;
const uint8_t EXTCODECOPY = 0x3c;
const uint8_t RETURNDATASIZE = 0x3d;
const uint8_t RETURNDATACOPY = 0x3e;

// Block Information
const uint8_t BLOCKHASH = 0x40;
const uint8_t COINBASE = 0x41;
const uint8_t TIMESTAMP = 0x42;
const uint8_t NUMBER = 0x43;
const uint8_t DIFFICULTY = 0x44;
const uint8_t GASLIMIT = 0x45;

// Stack, Memory, Storage and Flow Operations
const uint8_t POP = 0x50;
const uint8_t MLOAD = 0x51;
const uint8_t MSTORE = 0x52;
const uint8_t MSTORE8 = 0x53;
const uint8_t SLOAD = 0x54;
const uint8_t SSTORE = 0x55;
const uint8_t JUMP = 0x56;
const uint8_t JUMPI = 0x57;
const uint8_t PC = 0x58;
const uint8_t MSIZE = 0x59;
const uint8_t GAS = 0x5a;
const uint8_t JUMPDEST = 0x5b;

// Push Operations
const uint8_t PUSH1 = 0x60;
const uint8_t PUSH2 = 0x61;
const uint8_t PUSH3 = 0x62;
const uint8_t PUSH4 = 0x63;
const uint8_t PUSH5 = 0x64;
const uint8_t PUSH6 = 0x65;
const uint8_t PUSH7 = 0x66;
const uint8_t PUSH8 = 0x67;
const uint8_t PUSH9 = 0x68;
const uint8_t PUSH10 = 0x69;
const uint8_t PUSH11 = 0x6a;
const uint8_t PUSH12 = 0x6b;
const uint8_t PUSH13 = 0x6c;
const uint8_t PUSH14 = 0x6d;
const uint8_t PUSH15 = 0x6e;
const uint8_t PUSH16 = 0x6f;
const uint8_t PUSH17 = 0x70;
const uint8_t PUSH18 = 0x71;
const uint8_t PUSH19 = 0x72;
const uint8_t PUSH20 = 0x73;
const uint8_t PUSH21 = 0x74;
const uint8_t PUSH22 = 0x75;
const uint8_t PUSH23 = 0x76;
const uint8_t PUSH24 = 0x77;
const uint8_t PUSH25 = 0x78;
const uint8_t PUSH26 = 0x79;
const uint8_t PUSH27 = 0x7a;
const uint8_t PUSH28 = 0x7b;
const uint8_t PUSH29 = 0x7c;
const uint8_t PUSH30 = 0x7d;
const uint8_t PUSH31 = 0x7e;
const uint8_t PUSH32 = 0x7f;

// Duplicate Operations
const uint8_t DUP1 = 0x80;
const uint8_t DUP2 = 0x81;
const uint8_t DUP3 = 0x82;
const uint8_t DUP4 = 0x83;
const uint8_t DUP5 = 0x84;
const uint8_t DUP6 = 0x85;
const uint8_t DUP7 = 0x86;
const uint8_t DUP8 = 0x87;
const uint8_t DUP9 = 0x88;
const uint8_t DUP10 = 0x89;
const uint8_t DUP11 = 0x8a;
const uint8_t DUP12 = 0x8b;
const uint8_t DUP13 = 0x8c;
const uint8_t DUP14 = 0x8d;
const uint8_t DUP15 = 0x8e;
const uint8_t DUP16 = 0x8f;

// Exchange Operations
const uint8_t SWAP1 = 0x90;
const uint8_t SWAP2 = 0x91;
const uint8_t SWAP3 = 0x92;
const uint8_t SWAP4 = 0x93;
const uint8_t SWAP5 = 0x94;
const uint8_t SWAP6 = 0x95;
const uint8_t SWAP7 = 0x96;
const uint8_t SWAP8 = 0x97;
const uint8_t SWAP9 = 0x98;
const uint8_t SWAP10 = 0x99;
const uint8_t SWAP11 = 0x9a;
const uint8_t SWAP12 = 0x9b;
const uint8_t SWAP13 = 0x9c;
const uint8_t SWAP14 = 0x9d;
const uint8_t SWAP15 = 0x9e;
const uint8_t SWAP16 = 0x9f;

// Logging
const uint8_t LOG0 = 0xa0;
const uint8_t LOG1 = 0xa1;
const uint8_t LOG2 = 0xa2;
const uint8_t LOG3 = 0xa3;
const uint8_t LOG4 = 0xa4;

// System
const uint8_t CREATE = 0xf0;
const uint8_t CALL = 0xf1;
const uint8_t CALLCODE = 0xf2;
const uint8_t RETURN = 0xf3;
const uint8_t DELEGATECALL = 0xf4;
const uint8_t STATICCALL = 0xfa;
const uint8_t REVERT = 0xfd;
const uint8_t SELFDESTRUCT = 0xff;
