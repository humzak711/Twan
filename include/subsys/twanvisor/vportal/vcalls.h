#ifndef _VCALLS_H_
#define _VCALLS_H_

#include <subsys/twanvisor/varch.h>

typedef enum 
{
  VSUBSCRIBE_EXTERNAL_INTERRUPT_VECTOR = 0,
  VUNSUBSCRIBE_EXTERNAL_INTERRUPT_VECTOR = 1,

  VIPI = 2,
  VIPI_FAR = 3,
  VTLB_SHOOTDOWN = 4,

  VARM_TIMERN = 5,
  VDISARM_TIMERN = 6,

  VALTER_VCPU_TIMESLICE = 7,
  VALTER_VCPU_CRITICALITY = 8,

  VIS_SERVICED = 9,
  VIS_PENDING = 10,
  VEOI = 11,

  VYIELD = 12,
  VPAUSE = 13,

  VREAD_VCPU_STATE = 14,
  VREAD_VCPU_STATE_FAR = 15,

  VSET_ROUTE = 16,
  VSET_VCPU_SUBSCRIPTION_PERM = 17,
  VSET_CRITICALITY_PERM = 18,

  VREAD_CRITICALITY_LEVEL = 19,
  VWRITE_CRITICALITY_LEVEL = 20,

  VPV_SPIN_PAUSE = 21,
  VPV_SPIN_KICK = 22,
  VPV_SPIN_KICK_FAR = 23,

  VKDBG = 24,

  VCREATE_PARTITION = 25,
  VDESTROY_PARTITION = 26,

  VFRAME_SET = 27,
  VFRAME_UNSET = 28,
} vcall_ops_t;

typedef enum
{
    VIPI_DM_EXTERNAL = 0,
    VIPI_DM_UNPAUSE = 1
} vipi_ops_t;

/* 
    vcalls follow sysv 
    
    vcall id - rax
    arg1 - rdi
    arg2 - rsi
    arg3 - rdx
    arg4 - rcx
    arg5 - r8
    arg6 - r9

    return val - rax
*/

#define vcall_id(vregs) ((vregs)->regs.rax)
#define vcall_set_retval(vregs, ret) ((vregs)->regs.rax = (ret))

#define vcall_arg1_8(vregs) ((vregs)->regs.rdi & 0xff)
#define vcall_arg1_32(vregs) ((vregs)->regs.rdi & 0xffffffff)
#define vcall_arg1_64(vregs) ((vregs)->regs.rdi & 0xffffffffffffffff)

#define vcall_arg2_8(vregs) ((vregs)->regs.rsi & 0xff)
#define vcall_arg2_32(vregs) ((vregs)->regs.rsi & 0xffffffff)
#define vcall_arg2_64(vregs) ((vregs)->regs.rsi & 0xffffffffffffffff)

#define vcall_arg3_8(vregs) ((vregs)->regs.rdx & 0xff)
#define vcall_arg3_32(vregs) ((vregs)->regs.rdx & 0xffffffff)
#define vcall_arg3_64(vregs) ((vregs)->regs.rdx & 0xffffffffffffffff)

#define vcall_arg4_8(vregs) ((vregs)->regs.rcx & 0xff)
#define vcall_arg4_32(vregs) ((vregs)->regs.rcx & 0xffffffff)
#define vcall_arg4_64(vregs) ((vregs)->regs.rcx & 0xffffffffffffffff)

#define vcall_arg5_8(vregs) ((vregs)->regs.r8 & 0xff)
#define vcall_arg5_32(vregs) ((vregs)->regs.r8 & 0xffffffff)
#define vcall_arg5_64(vregs) ((vregs)->regs.r8 & 0xffffffffffffffff)

#define vcall_arg6_8(vregs)  ((vregs)->regs.r9 & 0xff)
#define vcall_arg6_32(vregs) ((vregs)->regs.r9 & 0xffffffff)
#define vcall_arg6_64(vregs) ((vregs)->regs.r9 & 0xffffffffffffffff)

typedef long (*vcall_func_t)(struct vregs *vregs);

void vcall_dispatcher(struct vregs *vregs);

#endif