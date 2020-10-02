//Defines here:
//#define CompileConsole
#define GoogleCPUFeatures

#ifdef __cplusplus
extern "C" {
#endif

#ifdef GoogleCPUFeatures
#include "../Google/cpuinfo_x86.h"
int GoogleSanityChecks() { return 80085; }
int GetCPUInstructions(int PlatformID, unsigned char* Buffer)
{
	switch(PlatformID)
	{
		case 0: { Buffer[0] = 0; return 1; } break; //Use software implementation.
		case 1: 
		{ 
			Buffer[0] = 1; //Platform.
			X86Features features = GetX86Info().features;
			Buffer[1] = GetX86FeaturesEnumValue(&features, X86_FPU);
			Buffer[2] = GetX86FeaturesEnumValue(&features, X86_TSC);
			Buffer[3] = GetX86FeaturesEnumValue(&features, X86_CX8);
			Buffer[4] = GetX86FeaturesEnumValue(&features, X86_CLFSH);
			Buffer[5] = GetX86FeaturesEnumValue(&features, X86_MMX);
			Buffer[6] = GetX86FeaturesEnumValue(&features, X86_AES);
			Buffer[7] = GetX86FeaturesEnumValue(&features, X86_ERMS);
			Buffer[8] = GetX86FeaturesEnumValue(&features, X86_F16C);
			Buffer[9] = GetX86FeaturesEnumValue(&features, X86_FMA3);
			Buffer[10] = GetX86FeaturesEnumValue(&features, X86_VAES);
			Buffer[11] = GetX86FeaturesEnumValue(&features, X86_VPCLMULQDQ);
			Buffer[12] = GetX86FeaturesEnumValue(&features, X86_BMI1);
			Buffer[13] = GetX86FeaturesEnumValue(&features, X86_HLE);
			Buffer[14] = GetX86FeaturesEnumValue(&features, X86_BMI2);
			Buffer[15] = GetX86FeaturesEnumValue(&features, X86_RTM);
			Buffer[16] = GetX86FeaturesEnumValue(&features, X86_RDSEED);
			Buffer[17] = GetX86FeaturesEnumValue(&features, X86_CLFLUSHOPT);
			Buffer[18] = GetX86FeaturesEnumValue(&features, X86_CLWB);
			Buffer[19] = GetX86FeaturesEnumValue(&features, X86_SSE);
			Buffer[20] = GetX86FeaturesEnumValue(&features, X86_SSE2);
			Buffer[21] = GetX86FeaturesEnumValue(&features, X86_SSE3);
			Buffer[22] = GetX86FeaturesEnumValue(&features, X86_SSSE3);
			Buffer[23] = GetX86FeaturesEnumValue(&features, X86_SSE4_1);
			Buffer[24] = GetX86FeaturesEnumValue(&features, X86_SSE4_2);
			Buffer[25] = GetX86FeaturesEnumValue(&features, X86_AVX);
			Buffer[26] = GetX86FeaturesEnumValue(&features, X86_AVX2);
			Buffer[27] = GetX86FeaturesEnumValue(&features, X86_AVX512F);
			Buffer[28] = GetX86FeaturesEnumValue(&features, X86_AVX512CD);
			Buffer[29] = GetX86FeaturesEnumValue(&features, X86_AVX512ER);
			Buffer[30] = GetX86FeaturesEnumValue(&features, X86_AVX512PF);
			Buffer[31] = GetX86FeaturesEnumValue(&features, X86_AVX512BW);
			Buffer[32] = GetX86FeaturesEnumValue(&features, X86_AVX512DQ);
			Buffer[33] = GetX86FeaturesEnumValue(&features, X86_AVX512VL);
			Buffer[34] = GetX86FeaturesEnumValue(&features, X86_AVX512IFMA);
			Buffer[35] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI);
			Buffer[36] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI2);
			Buffer[37] = GetX86FeaturesEnumValue(&features, X86_AVX512VNNI);
			Buffer[38] = GetX86FeaturesEnumValue(&features, X86_AVX512BITALG);
			Buffer[39] = GetX86FeaturesEnumValue(&features, X86_AVX512VPOPCNTDQ);
			Buffer[40] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VNNIW);
			Buffer[41] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VBMI2);
			Buffer[42] = GetX86FeaturesEnumValue(&features, X86_PCLMULQDQ);
			Buffer[43] = GetX86FeaturesEnumValue(&features, X86_SMX);
			Buffer[44] = GetX86FeaturesEnumValue(&features, X86_SGX);
			Buffer[45] = GetX86FeaturesEnumValue(&features, X86_CX16);
			Buffer[46] = GetX86FeaturesEnumValue(&features, X86_SHA);
			Buffer[47] = GetX86FeaturesEnumValue(&features, X86_POPCNT);
			Buffer[48] = GetX86FeaturesEnumValue(&features, X86_MOVBE);
			Buffer[49] = GetX86FeaturesEnumValue(&features, X86_RDRND);
			Buffer[50] = GetX86FeaturesEnumValue(&features, X86_DCA);
			Buffer[51] = GetX86FeaturesEnumValue(&features, X86_SS);
			Buffer[52] = GetX86FeaturesEnumValue(&features, X86_LAST_);
			return 53;
		} 
		break; //x86.
		case 2: 
		{ 
			Buffer[0] = 2; //Platform.
			X86Features features = GetX86Info().features;
			Buffer[1] = GetX86FeaturesEnumValue(&features, X86_FPU);
			Buffer[2] = GetX86FeaturesEnumValue(&features, X86_TSC);
			Buffer[3] = GetX86FeaturesEnumValue(&features, X86_CX8);
			Buffer[4] = GetX86FeaturesEnumValue(&features, X86_CLFSH);
			Buffer[5] = GetX86FeaturesEnumValue(&features, X86_MMX);
			Buffer[6] = GetX86FeaturesEnumValue(&features, X86_AES);
			Buffer[7] = GetX86FeaturesEnumValue(&features, X86_ERMS);
			Buffer[8] = GetX86FeaturesEnumValue(&features, X86_F16C);
			Buffer[9] = GetX86FeaturesEnumValue(&features, X86_FMA3);
			Buffer[10] = GetX86FeaturesEnumValue(&features, X86_VAES);
			Buffer[11] = GetX86FeaturesEnumValue(&features, X86_VPCLMULQDQ);
			Buffer[12] = GetX86FeaturesEnumValue(&features, X86_BMI1);
			Buffer[13] = GetX86FeaturesEnumValue(&features, X86_HLE);
			Buffer[14] = GetX86FeaturesEnumValue(&features, X86_BMI2);
			Buffer[15] = GetX86FeaturesEnumValue(&features, X86_RTM);
			Buffer[16] = GetX86FeaturesEnumValue(&features, X86_RDSEED);
			Buffer[17] = GetX86FeaturesEnumValue(&features, X86_CLFLUSHOPT);
			Buffer[18] = GetX86FeaturesEnumValue(&features, X86_CLWB);
			Buffer[19] = GetX86FeaturesEnumValue(&features, X86_SSE);
			Buffer[20] = GetX86FeaturesEnumValue(&features, X86_SSE2);
			Buffer[21] = GetX86FeaturesEnumValue(&features, X86_SSE3);
			Buffer[22] = GetX86FeaturesEnumValue(&features, X86_SSSE3);
			Buffer[23] = GetX86FeaturesEnumValue(&features, X86_SSE4_1);
			Buffer[24] = GetX86FeaturesEnumValue(&features, X86_SSE4_2);
			Buffer[25] = GetX86FeaturesEnumValue(&features, X86_AVX);
			Buffer[26] = GetX86FeaturesEnumValue(&features, X86_AVX2);
			Buffer[27] = GetX86FeaturesEnumValue(&features, X86_AVX512F);
			Buffer[28] = GetX86FeaturesEnumValue(&features, X86_AVX512CD);
			Buffer[29] = GetX86FeaturesEnumValue(&features, X86_AVX512ER);
			Buffer[30] = GetX86FeaturesEnumValue(&features, X86_AVX512PF);
			Buffer[31] = GetX86FeaturesEnumValue(&features, X86_AVX512BW);
			Buffer[32] = GetX86FeaturesEnumValue(&features, X86_AVX512DQ);
			Buffer[33] = GetX86FeaturesEnumValue(&features, X86_AVX512VL);
			Buffer[34] = GetX86FeaturesEnumValue(&features, X86_AVX512IFMA);
			Buffer[35] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI);
			Buffer[36] = GetX86FeaturesEnumValue(&features, X86_AVX512VBMI2);
			Buffer[37] = GetX86FeaturesEnumValue(&features, X86_AVX512VNNI);
			Buffer[38] = GetX86FeaturesEnumValue(&features, X86_AVX512BITALG);
			Buffer[39] = GetX86FeaturesEnumValue(&features, X86_AVX512VPOPCNTDQ);
			Buffer[40] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VNNIW);
			Buffer[41] = GetX86FeaturesEnumValue(&features, X86_AVX512_4VBMI2);
			Buffer[42] = GetX86FeaturesEnumValue(&features, X86_PCLMULQDQ);
			Buffer[43] = GetX86FeaturesEnumValue(&features, X86_SMX);
			Buffer[44] = GetX86FeaturesEnumValue(&features, X86_SGX);
			Buffer[45] = GetX86FeaturesEnumValue(&features, X86_CX16);
			Buffer[46] = GetX86FeaturesEnumValue(&features, X86_SHA);
			Buffer[47] = GetX86FeaturesEnumValue(&features, X86_POPCNT);
			Buffer[48] = GetX86FeaturesEnumValue(&features, X86_MOVBE);
			Buffer[49] = GetX86FeaturesEnumValue(&features, X86_RDRND);
			Buffer[50] = GetX86FeaturesEnumValue(&features, X86_DCA);
			Buffer[51] = GetX86FeaturesEnumValue(&features, X86_SS);
			Buffer[52] = GetX86FeaturesEnumValue(&features, X86_LAST_);
			return 53;
		}
		break; //x86_64.
		case 3: 
		{ 
		
		} 
		break; //ARM.
		case 4: 
		{ 
		
		} 
		break; //ARM64.
		case 5: 
		{ 
		
		} 
		break; //MIPS.
		case 6: 
		{
			
		} 
		break; //MIPS64.
		case 7: 
		{
			
		}
		break; //PowerPC
	}
}
#endif

int SanityChecks() { return 80085; }


#ifdef __cplusplus
}
#endif

#ifdef CompileConsole
void main()
{

}
#endif