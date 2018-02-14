## Smart contract execution

Step by step inspection of smart contract execution by EVM.
We will use [truffle](http://truffleframework.com/) to compile, and disassemble `SimpleStorag` contract. 

```
pragma solidity ^0.4.0;

contract SimpleStorage {
    uint storedData;

    function set(uint x) public {
        storedData = x;
    }

    function get() public constant returns (uint) {
        return storedData;
    }
}
```
Let's disassemble into EVM opcodes:
```bash 
$ truffle opcode SimpleStorage

0:   PUSH1 0x60
1:   PUSH1 0x40
2:   MSTORE 
3:   PUSH1 0x04
4:   CALLDATASIZE 
5:   LT 
6:   PUSH1 0x49
7:   JUMPI 
8:   PUSH1 0x00
9:   CALLDATALOAD 
10:  PUSH29 0x0100000000000000000000000000000000000000000000000000000000
11:  SWAP1 
12:  DIV 
13:  PUSH4 0xffffffff
14:  AND 
15:  DUP1 
16:  PUSH4 0x60fe47b1
17:  EQ 
18:  PUSH1 0x4e
19:  JUMPI 
20:  DUP1 
21:  PUSH4 0x6d4ce63c
22:  EQ 
23:  PUSH1 0x6e
24:  JUMPI 
25:  JUMPDEST 
26:  PUSH1 0x00
27:  DUP1 
28:  REVERT 
29:  JUMPDEST 
30:  CALLVALUE 
31:  ISZERO 
32:  PUSH1 0x58
33:  JUMPI 
34:  PUSH1 0x00
35:  DUP1 
36:  REVERT 
37:  JUMPDEST 
38:  PUSH1 0x6c
39:  PUSH1 0x04
40:  DUP1 
41:  DUP1 
42:  CALLDATALOAD 
43:  SWAP1 
44:  PUSH1 0x20
45:  ADD 
46:  SWAP1 
47:  SWAP2 
48:  SWAP1 
49:  POP 
50:  POP 
51:  PUSH1 0x94
52:  JUMP 
53:  JUMPDEST 
54:  STOP 
55:  JUMPDEST 
56:  CALLVALUE 
57:  ISZERO 
58:  PUSH1 0x78
59:  JUMPI 
60:  PUSH1 0x00
61:  DUP1 
62:  REVERT 
63:  JUMPDEST 
64:  PUSH1 0x7e
65:  PUSH1 0x9e
66:  JUMP 
67:  JUMPDEST 
68:  PUSH1 0x40
69:  MLOAD 
70:  DUP1 
71:  DUP3 
72:  DUP2 
73:  MSTORE 
74:  PUSH1 0x20
75:  ADD 
76:  SWAP2 
77:  POP 
78:  POP 
79:  PUSH1 0x40
80:  MLOAD 
81:  DUP1 
82:  SWAP2 
83:  SUB 
84:  SWAP1 
85:  RETURN 
86:  JUMPDEST 
87:  DUP1 
88:  PUSH1 0x00
89:  DUP2 
90:  SWAP1 
91:  SSTORE 
92:  POP 
93:  POP 
94:  JUMP 
95:  JUMPDEST 
96:  PUSH1 0x00
97:  DUP1 
98:  SLOAD 
99:  SWAP1 
100: POP 
101: SWAP1 
102: JUMP 
103: STOP
```
