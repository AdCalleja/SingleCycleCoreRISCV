# Entity: DataMemory

- **File**: DataMemory.v
## Diagram

![Diagram](DataMemory.svg "Diagram")
## Generics

| Generic name | Type | Value | Description |
| ------------ | ---- | ----- | ----------- |
| DATA_WIDTH   |      | 32    |             |
| ADDR_WIDTH   |      | 4     |             |
## Ports

| Port name | Direction | Type               | Description |
| --------- | --------- | ------------------ | ----------- |
| clk       | input     |                    |             |
| data_in   | input     | [(DATA_WIDTH-1):0] |             |
| addr      | input     | [(ADDR_WIDTH-1):0] |             |
| we        | input     |                    |             |
| re        | input     |                    |             |
| data_out  | output    | [(DATA_WIDTH-1):0] |             |
## Signals

| Name | Type                 | Description |
| ---- | -------------------- | ----------- |
| ram  | reg [DATA_WIDTH-1:0] |             |
## Processes
- unnamed: ( @(posedge clk) )
  - **Type:** always
