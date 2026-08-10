with Ada.Text_IO;
with Ada.Integer_Text_IO;
with Ada.Long_Float_Text_IO;

use Ada.Text_IO;
use Ada.Integer_Text_IO;
use Ada.Long_Float_Text_IO;

procedure Main is
    S : String (1 .. 100000);
    Last : Natural;
    P : Long_Float;
    Cnt1 : Integer := 0;
    CntR : Integer := 0;
    Res : Long_Float;
begin
    Get_Line (S, Last);
    Get (P);

    for I in 1 .. Last loop
        if S (I) = '1' then
            Cnt1 := Cnt1 + 1;
        elsif S (I) = '?' then
            CntR := CntR + 1;
        end if;
    end loop;

    Res := Long_Float (Cnt1 + CntR) * P;
    Res := (Long_Float (Cnt1) + Long_Float (CntR) * P) / Long_Float (Last);

    Put (Res, Fore => 1, Aft => 5, Exp => 0);
    New_Line;
end Main;