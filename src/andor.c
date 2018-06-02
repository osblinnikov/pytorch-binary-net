#include <TH/TH.h>

int andor_forward(THFloatTensor *input1, THFloatTensor *input2,
		       THFloatTensor *output)
{
  if (!THFloatTensor_isSameSizeAs(input1, input2))
    return 0;
  THFloatTensor_resizeAs(output, input1);
  THFloatTensor_cadd(output, input1, 1.0, input2);
  return 1;
}

int andor_backward(THFloatTensor *grad_output, THFloatTensor *grad_input)
{
  THFloatTensor_resizeAs(grad_input, grad_output);
  THFloatTensor_fill(grad_input, 1);
  return 1;
}
