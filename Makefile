# Get the newest cpp file
# Use PowerShell to get the latest .cpp file by last write time
# Get the latest .cpp file using PowerShell
LATEST_CPP := $(shell powershell -Command "(Get-ChildItem -Filter *.cpp | Sort-Object LastWriteTime -Descending | Select-Object -First 1).Name")

# Extract the base filename without extension
BASE_NAME := $(basename $(LATEST_CPP))
run:
	@echo Compiling latest file: $(LATEST_CPP)
	g++ "$(LATEST_CPP)" -o "$(BASE_NAME).exe"
	@echo Running output:
	./$(BASE_NAME).exe

