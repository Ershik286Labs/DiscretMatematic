program discrt.pas;

var
  f: Text;
  c, n: LongInt;
  a: array[1..200000] of LongInt;
  tmp_num, i, j: LongInt;

begin
  // Открываем файл для чтения
  Assign(f, 'input.txt');
  Reset(f);
  
  // Считываем количество чисел
  ReadLn(f, n);
  
  // Считываем числа из файла в массив
  for i := 1 to n do
    ReadLn(f, a[i]);
    
  Close(f);

  // Сортировка выбором
  for i := 1 to n do 
  begin
    tmp_num := i; // номер минимального среди элементов с индексами от i до n
    for j := i + 1 to n do
      if a[j] < a[tmp_num] then
        tmp_num := j;
    
    // Обмен значениями
    if tmp_num <> i then
    begin
      c := a[i];
      a[i] := a[tmp_num];
      a[tmp_num] := c;
    end;
  end;

  // Открываем файл для записи результата
  Assign(f, 'output.txt');
  Rewrite(f);
  
  // Записываем отсортированные числа в файл
  for j := 1 to n do
    WriteLn(f, a[j]);
    
  Close(f);
end.