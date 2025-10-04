with Ada.Text_IO;              use Ada.Text_IO;
with Ada.Strings.Unbounded;    use Ada.Strings.Unbounded;
with Ada.Strings.Fixed;        use Ada.Strings.Fixed;
with Ada.Characters.Handling;  use Ada.Characters.Handling;

procedure Main is
   s    : String (1 .. 200);
   last : Natural;
   N    : constant Natural := 1000;
   keys : array (1 .. N) of Unbounded_String;
   cnt  : array (1 .. N) of Natural := (others => 0);
   k    : Natural := 0;

   function normalize(s : String; len : Natural) return Unbounded_String is
      buf : String (1 .. 200);
      p   : Natural := 0;
      sp  : Boolean := True;
      c   : Character;
   begin
      if len < 2 then
         return To_Unbounded_String ("");
      end if;
      for i in 2 .. len loop
         c := s (i);
         if c = ' ' then
            if sp then
               null;
            else
               p := p + 1;
               buf (p) := ' ';
               sp := True;
            end if;
         elsif c in '0' .. '9' then
            p := p + 1;
            buf (p) := c;
            sp := False;
         elsif Is_Letter (c) then
            p := p + 1;
            buf (p) := To_Lower (c);
            sp := False;
         else
            null;
         end if;
      end loop;
      if p > 0 and then buf (p) = ' ' then
         p := p - 1;
      end if;
      if p = 0 then
         return To_Unbounded_String ("");
      else
         return To_Unbounded_String (buf (1 .. p));
      end if;
   end normalize;

   procedure add_key(kstr : Unbounded_String) is
      ok : Boolean := False;
   begin
      if kstr = To_Unbounded_String ("") then
         return;
      end if;
      for i in 1 .. k loop
         if To_String (keys (i)) = To_String (kstr) then
            cnt (i) := cnt (i) + 1;
            ok := True;
            exit;
         end if;
      end loop;
      if not ok then
         k := k + 1;
         keys (k) := kstr;
         cnt (k) := 1;
      end if;
   end add_key;

   mx   : Natural := 0;
   res  : array (1 .. N) of Unbounded_String;
   r    : Natural := 0;

   function less_str(a, b : Unbounded_String) return Boolean is
   begin
      return To_String (a) < To_String (b);
   end less_str;

begin
   while not End_Of_File loop
      Get_Line (s, last);
      if last = 0 then
         null;
      else
         if s (s'First) = '*' then
            add_key (normalize (s, last));
         end if;
      end if;
   end loop;

   for i in 1 .. k loop
      if cnt (i) > mx then
         mx := cnt (i);
      end if;
   end loop;

   for i in 1 .. k loop
      if cnt (i) = mx then
         r := r + 1;
         res (r) := keys (i);
      end if;
   end loop;

   if r > 1 then
      for j in 2 .. r loop
         declare
            tmp : Unbounded_String := res (j);
            pos : Natural := j;
         begin
            while pos > 1 and then less_str (tmp, res (pos - 1)) loop
               res (pos) := res (pos - 1);
               pos := pos - 1;
            end loop;
            res (pos) := tmp;
         end;
      end loop;
   end if;

   for i in 1 .. r loop
      Put_Line (To_String (res (i)));
   end loop;
end Main;
