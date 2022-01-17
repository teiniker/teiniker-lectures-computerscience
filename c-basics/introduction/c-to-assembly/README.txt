gcc 

(gdb) disass max_value 
Dump of assembler code for function max_value:
   0x0000000000001135 <+0>:     push   %rbp
   0x0000000000001136 <+1>:     mov    %rsp,%rbp
   0x0000000000001139 <+4>:     mov    %edi,-0x4(%rbp)
   0x000000000000113c <+7>:     mov    %esi,-0x8(%rbp)
   0x000000000000113f <+10>:    mov    -0x4(%rbp),%eax
   0x0000000000001142 <+13>:    cmp    -0x8(%rbp),%eax
   0x0000000000001145 <+16>:    jle    0x114c <max_value+23>
   0x0000000000001147 <+18>:    mov    -0x4(%rbp),%eax
   0x000000000000114a <+21>:    jmp    0x114f <max_value+26>
   0x000000000000114c <+23>:    mov    -0x8(%rbp),%eax
   0x000000000000114f <+26>:    pop    %rbp
   0x0000000000001150 <+27>:    ret   

   (gdb) disass add_values 
Dump of assembler code for function add_values:
   0x0000000000001151 <+0>:     push   %rbp
   0x0000000000001152 <+1>:     mov    %rsp,%rbp
   0x0000000000001155 <+4>:     mov    %edi,-0x4(%rbp)
   0x0000000000001158 <+7>:     mov    %esi,-0x8(%rbp)
   0x000000000000115b <+10>:    mov    -0x4(%rbp),%edx
   0x000000000000115e <+13>:    mov    -0x8(%rbp),%eax
   0x0000000000001161 <+16>:    add    %edx,%eax
   0x0000000000001163 <+18>:    pop    %rbp
   0x0000000000001164 <+19>:    ret    

(gdb) disass add_first_values 
Dump of assembler code for function add_first_values:
   0x0000000000001165 <+0>:     push   %rbp
   0x0000000000001166 <+1>:     mov    %rsp,%rbp
   0x0000000000001169 <+4>:     mov    %edi,-0x14(%rbp)
   0x000000000000116c <+7>:     movl   $0x0,-0x4(%rbp)
   0x0000000000001173 <+14>:    movl   $0x1,-0x8(%rbp)
   0x000000000000117a <+21>:    jmp    0x1186 <add_first_values+33>
   0x000000000000117c <+23>:    mov    -0x8(%rbp),%eax
   0x000000000000117f <+26>:    add    %eax,-0x4(%rbp)
   0x0000000000001182 <+29>:    addl   $0x1,-0x8(%rbp)
   0x0000000000001186 <+33>:    mov    -0x8(%rbp),%eax
   0x0000000000001189 <+36>:    cmp    -0x14(%rbp),%eax
   0x000000000000118c <+39>:    jle    0x117c <add_first_values+23>
   0x000000000000118e <+41>:    mov    -0x4(%rbp),%eax
   0x0000000000001191 <+44>:    pop    %rbp
   0x0000000000001192 <+45>:    ret       


$ gcc -O2 c_to_assembly.c -o c_to_assembly 
$ gdb ./c_to_assembly
$ objdump -d c_to_assembly

(gdb) disass max_value 
Dump of assembler code for function max_value:
   0x0000000000001160 <+0>:     cmp    %esi,%edi
   0x0000000000001162 <+2>:     mov    %esi,%eax
   0x0000000000001164 <+4>:     cmovge %edi,%eax
   0x0000000000001167 <+7>:     ret  

0000000000001160 <max_value>:
    1160:       39 f7                   cmp    %esi,%edi
    1162:       89 f0                   mov    %esi,%eax
    1164:       0f 4d c7                cmovge %edi,%eax
    1167:       c3                      retq   
    1168:       0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
    116f:       00 


(gdb) disass add_values 
Dump of assembler code for function add_values:
   0x0000000000001170 <+0>:     lea    (%rdi,%rsi,1),%eax
   0x0000000000001173 <+3>:     ret  

0000000000001170 <add_values>:
    1170:       8d 04 37                lea    (%rdi,%rsi,1),%eax
    1173:       c3                      retq   
    1174:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
    117b:       00 00 00 00 
    117f:       90                      nop


(gdb) disass add_first_values 
Dump of assembler code for function add_first_values:
   0x0000000000001180 <+0>:     test   %edi,%edi
   0x0000000000001182 <+2>:     jle    0x11a0 <add_first_values+32>
   0x0000000000001184 <+4>:     add    $0x1,%edi
   0x0000000000001187 <+7>:     mov    $0x1,%eax
   0x000000000000118c <+12>:    xor    %r8d,%r8d
   0x000000000000118f <+15>:    nop
   0x0000000000001190 <+16>:    add    %eax,%r8d
   0x0000000000001193 <+19>:    add    $0x1,%eax
   0x0000000000001196 <+22>:    cmp    %edi,%eax
   0x0000000000001198 <+24>:    jne    0x1190 <add_first_values+16>
   0x000000000000119a <+26>:    mov    %r8d,%eax
   0x000000000000119d <+29>:    ret    
   0x000000000000119e <+30>:    xchg   %ax,%ax
   0x00000000000011a0 <+32>:    xor    %r8d,%r8d
   0x00000000000011a3 <+35>:    mov    %r8d,%eax
   0x00000000000011a6 <+38>:    ret    

0000000000001180 <add_first_values>:
    1180:       85 ff                   test   %edi,%edi
    1182:       7e 1c                   jle    11a0 <add_first_values+0x20>
    1184:       83 c7 01                add    $0x1,%edi
    1187:       b8 01 00 00 00          mov    $0x1,%eax
    118c:       45 31 c0                xor    %r8d,%r8d
    118f:       90                      nop
    1190:       41 01 c0                add    %eax,%r8d
    1193:       83 c0 01                add    $0x1,%eax
    1196:       39 f8                   cmp    %edi,%eax
    1198:       75 f6                   jne    1190 <add_first_values+0x10>
    119a:       44 89 c0                mov    %r8d,%eax
    119d:       c3                      retq   
    119e:       66 90                   xchg   %ax,%ax
    11a0:       45 31 c0                xor    %r8d,%r8d
    11a3:       44 89 c0                mov    %r8d,%eax
    11a6:       c3                      retq   
    11a7:       66 0f 1f 84 00 00 00    nopw   0x0(%rax,%rax,1)
    11ae:       00 00 