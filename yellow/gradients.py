import torch
import torch.nn as nn

class YourModel(nn.Module):
    def __init__(self) -> None:
        super(YourModel, self).__init__():
        # something init
    
    def forward(self, x):
        # something forward
        return x
    
model = YourModel()
criterion = nn.MSELoss()
x = torch.randn(1, inputSize)
output = model(x)
loss = criterion(output, target)
loss.backward()

total_norm = 0
for param in model.parameters():
    param_norm = param.grad.data.norm(2)
    total_norm += param_norm.item() ** 2
total_norm = total_norm ** 0.5

print("norm of theh gradient of the model: " + str(total_norm))