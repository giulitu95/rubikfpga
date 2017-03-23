library ieee;
use ieee.std_logic_1164.all

-- 3 bit register
entity register_3bit is
	port (	data_in: in std_logic_vector (2 downto 0);
		  	data_out: out std_logic_vector (2 downto 0);
		  	ck: in std_logic;
		  	reset: in std_logic
			);
end entity register_3bit;

architecture behavioral of register_3bit is
begin 
	process is
		if reset = 0 then
			data_out[0]<=data_in[0] when rising_edge(ck) else data_out[0];
			data_out[1]<=data_in[1] when rising_edge(ck) else data_out[1];
			data_out[2]<=data_in[2] when rising_edge(ck) else data_out[2];
		else 
			q <= "000" ;
		end if;

	end;
end architecture register_3bit;