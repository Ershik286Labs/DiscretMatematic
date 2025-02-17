 var A,B,C,D,E,X,Y,K: set of string;
 var C2: set of real;
 var n, i :integer;
 var el :string;
 var realTmp :real;
 var charTmp :char;
 var integerTmp, integerTmp2 :integer;
 var code :integer;
 var ok, tesk :integer;
 
 procedure readN();//считывание мощности алфавита
 begin
    ok := 1;
    while ok = 1 do begin
      try
        Readln(&n);//считываем число, которое отвечает за мощность алфавита
        ok := 0;
      except
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then ok := 0;
      end;
    end;
 end;
 
 begin
    Writeln('Введите мощность A (действительные):');
    readN();
    Writeln('Введите элементы:');
    i := 0;
    while i < n do begin //цикл ввода, для того чтобы оно работало, пока пользователь не заполнит
      try
        Readln(&realTmp);
        el := FloatToStr(realTmp); //переводим в строку
        if el in A then begin //введенное число есть в множестве или нет
          Writeln('Уже есть');
        end else begin
          Include(A, el); // включаем во множества, если этого элемента нет в множестве
          i := i + 1;
        end;
      except
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then i := n;
      end;
    end;
    
    
    Writeln('Введите мощность B (рациональные):');
    readN();
    Writeln('Введите элементы:');
    i := 0;
    while i < n do begin
      try
        Readln(&integerTmp); //считывание рациональных чисел в 2 части, в начале целую часть, потом дробную часть
        Readln(&realTmp);
        Str(integerTmp, &el);
        el := el + '/' + FloatToStr(realTmp); //добавляем дробную черту
        realTmp := integerTmp / realTmp; //делим для получения числового значения
        if el in B then begin
          Writeln('Уже есть');
        end else begin
          Include(B, el);
          i := i + 1;
        end;
      except
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then i := n;
      end;
    end;
    
    Writeln('Введите мощность C (целые):');
    readN();
    Writeln('Введите элементы (в формате целая ...):');
    i := 0;
    while i < n do begin
      try
        Readln(&integerTmp);
        Str(integerTmp, &el);
        if el in A then begin
          Writeln('Уже есть');
        end else begin
          Include(С, el);
          i := i + 1;
        end;
      except
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then i := n;
      end;
    end;
    
    
    Writeln('Введите мощность D (лат):');
    readN();
    Writeln('Введите элементы:');
    i := 0;
    while i < n do begin
      Readln(&charTmp);
      el := charTmp;
      tesk:= integer(charTmp);
      writeln(tesk);
      if (65 <= Ord(charTmp)) and (Ord(charTmp) <= 122) then begin //кодовые значения у английского алфавита
        if el in D then begin
          Writeln('Уже есть');
        end else begin
          Include(D, el);
          i := i + 1;
        end;
      end else begin
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then i := n;
      end;
    end;
    
    
    Writeln('Введите мощность E (рус):');
    readN();
    Writeln('Введите элементы:');
    i := 0;
    while i < n do begin
      Readln(&charTmp);
      el := charTmp;
      tesk:= integer(charTmp);
      writeln(tesk);
      if (1040 <= Ord(charTmp)) and (Ord(charTmp) <= 1103) then begin //кодовые значения у русских символов
        if el in E then begin
          Writeln('Уже есть');
        end else begin
          Include(E, el);
          i := i + 1;
        end;
      end else begin
          Writeln('Некорректный ввод, желаете повторить (0 - нет, 1 - да)?');
          Readln(&integerTmp);
          if integerTmp = 0 then i := n;
      end;
    end;
    
    Writeln('A (действительные) = ', A);
    Writeln('B (рациональные) = ', B);
    Writeln('C (целые) = ', C);
    Writeln('D (лат)= ', D);
    Writeln('E (рус) = ', E);
   
    X := A + B + C;
    Y := E * D;
    K := X - Y;
    Writeln('X (пересечение A,B,C) = ', X);
    Writeln('Y (объединение E,D) = ', Y);
    Writeln('K (разность X\Y)= ', K);
    Writeln('K мощность = ', K.count);
 end.