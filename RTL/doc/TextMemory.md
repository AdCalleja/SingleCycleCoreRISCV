# Entity: TextMemory

- **File**: TextMemory.v
## Diagram

![Diagram](TextMemory.svg "Diagram")
## Generics

| Generic name | Type | Value | Description |
| ------------ | ---- | ----- | ----------- |
| DATA_WIDTH   |      | 32    |             |
| ADDR_WIDTH   |      | 8     |             |
## Ports

| Port name | Direction | Type               | Description |
| --------- | --------- | ------------------ | ----------- |
| addr      | input     | [(ADDR_WIDTH-1):0] |             |
| data_out  | output    | [(DATA_WIDTH-1):0] |             |
## Processes
- unnamed: ( @(*) )
  - **Type:** always
  - **Description**
  Internal memory instantation 
