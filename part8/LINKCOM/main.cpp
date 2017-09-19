#include <mkl.h>
#include <mkl_vsl.h>

int main(){
	DFTI_DESCRIPTOR_HANDLE fft_handle;
	MKL_LONG status;
	MKL_Complex8 in[512];
	MKL_Complex8 out[512];
	status = DftiCreateDescriptor(&fft_handle, DFTI_SINGLE, DFTI_COMPLEX, 1, 512);
	status = DftiCommitDescriptor(fft_handle);
	status = DftiSetValue(fft_handle, DFTI_PLACEMENT, DFTI_NOT_INPLACE);
	status = DftiCommitDescriptor(fft_handle);
	DftiComputeBackward(fft_handle, in, out);
	return 0;
}
