//Defines here:
//#define CompileConsole
#define GoogleCPUFeatures

//#define x86_Steroids
#define x86_64_Steroids
//#define ARM_Steroids
//#define ARM64_Steroids
//#define MIPS_Steroids
//#define MIPS64_Steroids
//#define PowerPC_Steroids


#ifdef __cplusplus
extern "C" {
#endif

#ifdef GoogleCPUFeatures
#if defined x86_Steroids  || defined x86_64_Steroids
#include "../Google/cpuinfo_x86.h"
#endif
#if defined ARM_Steroids  || defined ARM64_Steroids
#include "../Google/cpuinfo_arm.h"
#endif
int GoogleSanityChecks() { return 80085; }
int GetCPUInstructions(int PlatformID, unsigned char* Buffer)
{
	switch(PlatformID)
	{
		case 0: { Buffer[0] = 0; return 1; } break; //Use software implementation.
		case 1: 
		case 2:
		{ 
#if defined x86_Steroids  || defined x86_64_Steroids
			Buffer[0] = PlatformID; //Platform.
			X86Features features = GetX86Info().features; //More info: https://en.wikipedia.org/wiki/CPUID
			Buffer[1] = GetX86FeaturesEnumValue(&features, X86_FPU); //Onboard x87 FPU
			Buffer[2] = GetX86FeaturesEnumValue(&features, X86_TSC); //Time Stamp Counter
			Buffer[3] = GetX86FeaturesEnumValue(&features, X86_CX8); //CMPXCHG8 (compare-and-swap) instruction
			Buffer[4] = GetX86FeaturesEnumValue(&features, X86_CLFSH); //CLFLUSH instruction (SSE2)
			Buffer[5] = GetX86FeaturesEnumValue(&features, X86_MMX); //MMX instructions
			Buffer[6] = GetX86FeaturesEnumValue(&features, X86_AES); //AES instruction set
			Buffer[7] = GetX86FeaturesEnumValue(&features, X86_ERMS); //Enhanced REP MOVSB/STOSB
			Buffer[8] = GetX86FeaturesEnumValue(&features, X86_F16C); //F16C (half-precision) FP feature
			Buffer[9] = GetX86FeaturesEnumValue(&features, X86_FMA3); //Fused multiply-add (FMA3)
			Buffer[10] = GetX86FeaturesEnumValue(&features, X86_VAES); //Vector AES instruction set (VEX-256/EVEX)
			Buffer[11] = GetX86FeaturesEnumValue(&features, X86_VPCLMULQDQ); //CLMUL instruction set (VEX-256/EVEX)
			Buffer[12] = GetX86FeaturesEnumValue(&features, X86_BMI1); //Bit Manipulation Instruction Set 1
			Buffer[13] = GetX86FeaturesEnumValue(&features, X86_HLE); //TSX Hardware Lock Elision
			Buffer[14] = GetX86FeaturesEnumValue(&features, X86_BMI2); //Bit Manipulation Instruction Set 2
			Buffer[15] = GetX86FeaturesEnumValue(&features, X86_RTM); //TSX Restricted Transactional Memory
			Buffer[16] = GetX86FeaturesEnumValue(&features, X86_RDSEED); //RDSEED instruction
			Buffer[17] = GetX86FeaturesEnumValue(&features, X86_CLFLUSHOPT); //CLFLUSHOPT instruction
			Buffer[18] = GetX86FeaturesEnumValue(&features, X86_CLWB); //CLWB instruction
			Buffer[19] = GetX86FeaturesEnumValue(&features, X86_SSE); //SSE instructions (a.k.a. Katmai New Instructions)
			Buffer[20] = GetX86FeaturesEnumValue(&features, X86_SSE2); //SSE2 instructions
			Buffer[21] = GetX86FeaturesEnumValue(&features, X86_SSE3); //Prescott New Instructions-SSE3 (PNI)
			Buffer[22] = GetX86FeaturesEnumValue(&features, X86_SSSE3); //Supplemental SSE3 instructions
			Buffer[23] = GetX86FeaturesEnumValue(&features, X86_SSE4_1); //SSE4.1 instructions
			Buffer[24] = GetX86FeaturesEnumValue(&features, X86_SSE4_2); //SSE4.2 instructions
			Buffer[25] = GetX86FeaturesEnumValue(&features, X86_AVX); //Advanced Vector Extensions
			Buffer[26] = GetX86FeaturesEnumValue(&features, X86_AVX2); //Advanced Vector Extensions 2
			Buffer[27] = GetX86FeaturesEnumValue(&features, X86_AVX512F); //AVX-512 Foundation
			Buffer[28] = GetX86FeaturesEnumValue(&features, X86_AVX512CD); //AVX-512 Conflict Detection Instructions
			Buffer[29] = GetX86FeaturesEnumValue(&features, X86_AVX512ER); //AVX-512 Exponential and Reciprocal Instructions
			Buffer[30] = GetX86FeaturesEnumValue(&features, X86_AVX512PF); //AVX-512 Prefetch Instructions
			Buffer[31] = GetX86FeaturesEnumValue(&features, X86_AVX512BW); //AVX-512 Byte and Word Instructions
			Buffer[32] = GetX86FeaturesEnumValue(&features, X86_AVX512DQ); //AVX-512 Doubleword and Quadword Instructions
			Buffer[33] = GetX86FeaturesEnumValue(&features, X86_AVX512VL); //AVX-512 Vector Length Extensions
			Buffer[34] = GetX86FeaturesEnumValue(&features, X86_AVX512IFMA); //AVX-512 Integer Fused Multiply-Add Instructions
			Buffer[35] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI); //AVX-512 Vector Bit Manipulation Instructions
			Buffer[36] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI2); //AVX-512 Vector Bit Manipulation Instructions 2
			Buffer[37] = GetX86FeaturesEnumValue(&features, X86_AVX512VNNI); //AVX-512 Vector Neural Network Instructions
			Buffer[38] = GetX86FeaturesEnumValue(&features, X86_AVX512BITALG); //AVX-512 BITALG instructions
			Buffer[39] = GetX86FeaturesEnumValue(&features, X86_AVX512VPOPCNTDQ); //AVX-512 Vector Population Count Double and Quad-word
			Buffer[40] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VNNIW); //AVX-512 4-register Neural Network Instructions
			Buffer[41] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VBMI2); //AVX-512 Vector Bit Manipulation Instructions 2
			Buffer[42] = GetX86FeaturesEnumValue(&features, X86_PCLMULQDQ); //PCLMULQDQ
			Buffer[43] = GetX86FeaturesEnumValue(&features, X86_SMX); //Safer Mode Extensions (LaGrande)
			Buffer[44] = GetX86FeaturesEnumValue(&features, X86_SGX); //Software Guard Extensions
			Buffer[45] = GetX86FeaturesEnumValue(&features, X86_CX16); //CMPXCHG16B instruction 64
			Buffer[46] = GetX86FeaturesEnumValue(&features, X86_SHA); //Intel SHA extensions
			Buffer[47] = GetX86FeaturesEnumValue(&features, X86_POPCNT); //POPCNT instruction
			Buffer[48] = GetX86FeaturesEnumValue(&features, X86_MOVBE); //MOVBE instruction (big-endian)
			Buffer[49] = GetX86FeaturesEnumValue(&features, X86_RDRND); //RDRAND (on-chip random number generator) feature
			Buffer[50] = GetX86FeaturesEnumValue(&features, X86_DCA); //Direct cache access for DMA writes
			Buffer[51] = GetX86FeaturesEnumValue(&features, X86_SS); //CPU cache implements self-snoop
			
			//TODO: Find all instruction sets that apply to x64 only.

			return 52;
#else
			Buffer[0] = 0; return 1; //Defaults to software implementation.
#endif
		} 
		break; //x86/x86_64.
		case 3: 
		case 4:
		{
#if defined ARM_Steroids  || defined ARM64_Steroids
			Buffer[0] = Platform;  //Platform.
			ArmFeatures features = GetArmInfo().features;
			Buffer[1] = GetArmFeaturesEnumValue(&features, ARM_SWP); // SWP instruction (atomic read-modify-write)
			Buffer[2] = GetArmFeaturesEnumValue(&features, ARM_HALF); // Half-word loads and stores
			Buffer[3] = GetArmFeaturesEnumValue(&features, ARM_THUMB); // Thumb (16-bit instruction set)
			Buffer[4] = GetArmFeaturesEnumValue(&features, ARM_26BIT); // "26 Bit" Model (Processor status register folded into program counter)
			Buffer[5] = GetArmFeaturesEnumValue(&features, ARM_FASTMULT); // 32x32->64-bit multiplication
			Buffer[6] = GetArmFeaturesEnumValue(&features, ARM_FPA); // Floating point accelerator
			Buffer[7] = GetArmFeaturesEnumValue(&features, ARM_VFP); // Vector Floating Point.
			Buffer[8] = GetArmFeaturesEnumValue(&features, ARM_EDSP); // DSP extensions (the 'e' variant of the ARM9 CPUs, and all others above)
			Buffer[9] = GetArmFeaturesEnumValue(&features, ARM_JAVA); // Jazelle (Java bytecode accelerator)
			Buffer[10] = GetArmFeaturesEnumValue(&features, ARM_IWMMXT); // Intel Wireless MMX Technology.
			Buffer[11] = GetArmFeaturesEnumValue(&features, ARM_CRUNCH); // MaverickCrunch coprocessor
			Buffer[12] = GetArmFeaturesEnumValue(&features, ARM_THUMBEE); // ThumbEE
			Buffer[13] = GetArmFeaturesEnumValue(&features, ARM_NEON); // Advanced SIMD.
			Buffer[14] = GetArmFeaturesEnumValue(&features, ARM_VFPV3); // VFP version 3
			Buffer[15] = GetArmFeaturesEnumValue(&features, ARM_VFPV3D16); // VFP version 3 with 16 D-registers
			Buffer[16] = GetArmFeaturesEnumValue(&features, ARM_TLS); // TLS register
			Buffer[17] = GetArmFeaturesEnumValue(&features, ARM_VFPV4); // VFP version 4 with fast context switching
			Buffer[18] = GetArmFeaturesEnumValue(&features, ARM_IDIVA); // SDIV and UDIV hardware division in ARM mode.
			Buffer[19] = GetArmFeaturesEnumValue(&features, ARM_IDIVT); // SDIV and UDIV hardware division in Thumb mode.
			Buffer[20] = GetArmFeaturesEnumValue(&features, ARM_VFPD32); // VFP with 32 D-registers
			Buffer[21] = GetArmFeaturesEnumValue(&features, ARM_LPAE); // Large Physical Address Extension (>4GB physical memory on 32-bit architecture)
			Buffer[22] = GetArmFeaturesEnumValue(&features, ARM_EVTSTRM); // kernel event stream using generic architected timer
			Buffer[23] = GetArmFeaturesEnumValue(&features, ARM_AES); // Hardware-accelerated Advanced Encryption Standard.
			Buffer[24] = GetArmFeaturesEnumValue(&features, ARM_PMULL); // Polynomial multiply long.
			Buffer[25] = GetArmFeaturesEnumValue(&features, ARM_SHA1); // Hardware-accelerated SHA1.
			Buffer[26] = GetArmFeaturesEnumValue(&features, ARM_SHA2); // Hardware-accelerated SHA2-256.
			Buffer[27] = GetArmFeaturesEnumValue(&features, ARM_CRC32); // Hardware-accelerated CRC-32.
			if (Platform == 4) //ARM64 Extensions.
			{
				Buffer[28] = GetAarch64FeaturesEnumValue(&features, AARCH64_FP); // Floating-point.
				Buffer[29] = GetAarch64FeaturesEnumValue(&features, AARCH64_ASIMD); // Advanced SIMD.
				Buffer[30] = GetAarch64FeaturesEnumValue(&features, AARCH64_AES); // Hardware-accelerated Advanced Encryption Standard.
				Buffer[31] = GetAarch64FeaturesEnumValue(&features, AARCH64_PMULL); // Polynomial multiply long.
				Buffer[32] = GetAarch64FeaturesEnumValue(&features, AARCH64_SHA1); // Hardware-accelerated SHA1.
				Buffer[33] = GetAarch64FeaturesEnumValue(&features, AARCH64_SHA2); // Hardware-accelerated SHA2-256.
				Buffer[34] = GetAarch64FeaturesEnumValue(&features, AARCH64_CRC32); // Hardware-accelerated CRC-32.
				return 35;
			}
			else { return 28; }	
#else
			Buffer[0] = 0; return 1; //Defaults to software implementation.
#endif
		}
		break; //ARM.
		case 5: 
		{ 
#ifdef MIPS_Steroids
			Buffer[0] = 5;  //Platform.
			ArmFeatures features = GetArmInfo().features;
			Buffer[1] = GetArmFeaturesEnumValue(&features, ARM_SWP);
			return 2;
#else
			Buffer[0] = 0; return 1; //Defaults to software implementation.
#endif
		} 
		break; //MIPS.
		case 6: 
		{
#ifdef MIPS64_Steroids
			Buffer[0] = 6;  //Platform.
			ArmFeatures features = GetArmInfo().features;
			Buffer[1] = GetArmFeaturesEnumValue(&features, ARM_SWP);
			return 2;
#else
			Buffer[0] = 0; return 1; //Defaults to software implementation.
#endif
		} 
		break; //MIPS64.
		case 7: 
		{
#ifdef PowerPC_Steroids
			Buffer[0] = 7;  //Platform.
			ArmFeatures features = GetArmInfo().features;
			Buffer[1] = GetArmFeaturesEnumValue(&features, ARM_SWP);
			return 2;
#else
			Buffer[0] = 0; return 1; //Defaults to software implementation.
#endif
		}
		break; //PowerPC
	}
}
#endif

int SteroidsSanityChecks() { return 80085; }


#ifdef __cplusplus
}
#endif

#ifdef CompileConsole
void main()
{

}
#endif