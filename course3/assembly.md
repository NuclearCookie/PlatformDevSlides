#Assembly


##Registers (X86)

- EAX : Accumulator register
- EBX : Base register
- ECX : Counter register
- EDX : Data register
- ESI : Source index register
- EDI : Destination index register


##Special Registers

- ESP : Stack pointer
- EBP : Base stack pointer
- EIP : Instruction pointer
- EFL : Flags


##Generic Registers

- EAX : 32bit
- AX : 16bit
- AH : 8 bit
- AL : 8 bit


##Stack

- Memory allocated on application start
- Used to save local variable
- Also used to save return address from calls


##Stack

- Stack top is saved in ESP
- It grows downward
- PUSH / POP instructions


## PUSH

- PUSH EAX
    - MOV EAX, [ESP]
    - SUB ESP, 4


## POP

- POP EAX
    - MOV [ESP], EAX
    - ADD ESP, 4


##Special stack operation

- PUSHA / POPA ( push/pop all register )
- PUSHF / POPF ( push/pop flag register )


## Call

- Call function with CALL
- It pushes the current address on the stack
- Update EIP to the address of the call
- RET returns to calling site


##What about arguments

- Can be passed in registers
- Can be passed in the stack


##What about registers

- Can I change them?
- If I call another function, which one are preserved


## Lots of choices

- Defined in ABI ( Application Binary Interface )
- Defined in calling convention
    - stdcall
    - thiscall
    - fastcall
(https://en.wikipedia.org/wiki/X86_calling_conventions)


## Convention

- Stack cleanup
- Caller saved registers
- Callee saved registers


## 64Bits

- Registers are grown to 64Bit (RAX, RBX, RCX, ...)
- More registers ( R8, R9, R10, ..., R1 = RAX, R2 = RBX, ...)
