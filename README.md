# Курсовая работа по информатике
### Студента 3 курса МФТИ Б07-201
Хисматуллина Романа Камилевича
[Почта](romafgv8@gmail.com)
## Архитектура

Релизован MVC
- M - Manipulator:IManipulator
- V - Python code (future)
- C - Sequnce
---
M - содержит в себе список IPositionable - обертка любого отрисовываемого объекта. Предполагается, что View должен сам позаботиться о том, чтобы знать, кто есть кто в наследниках класса Positionable (иначе это сильно ограничет общность MC). M предоставляет методы для проверки коллизий и движения элементов. (Получаются уравнения окружностей, и проверяется, есть ли пересечения с неподвижными отрезками)

---
C действует на M c помощью IAction.
- IAction::DoWork(IManipulator* mm) отвечат за верность типа. Возвращает 0 - на успех, 1 - на ошибку в действие.
- IAction заботится о том, чтобы преобразование выполнялось с правильным элементом.
- Sequence::Next() возвращает 0 - на успех, -1 - на отсутствие следующего действия, N - номер действия, повлекшего ошибку. Более подробно, что произошло можно посмотреть в модели.
- Next() удаляет добавленные действия
- ~Manipulator() - удаляет добавленные элементы.
---

## Задание

# Робот-манипулятор
Приложение используется для хранения информации о роботе-манипуляторе и имитации его работы. Робот состоит из последовательно соединённых подвижных звеньев, к которым могут прикрепляться управляемые захваты и/или видеокамеры. 

Все звенья имеют форму отрезка прямой линии, толщина звеньев и их сочленений пренебрежимо мала. 

Звенья и захваты способны поворачиваться друг относительно друга вокруг заданных осей. Для простоты считается, что все звенья манипулятора располагаются в одной плоскости, оси вращения звеньев перпендикулярны ей. 

Звенья не образуют циклов (т.е. роботов параллельной структуры рассматривать не нужно).
Необходимые классы

### Подвижное звено: 
объект содержит:
- int N номер текущего звена (положительное число),
- int  N_PREV номер предыдущего звена в кинематической цепи (либо 0, если такого звена нет), 
- double  ALPHA положение звена относительно предыдущего (угол поворота звена),
- double X, Y 2 компонента вектора положения начала координат звена

Необходимо уметь:
задать поворот звена как до заданного угла,
так и на заданный угол.

### Захват: 
объект содержит:
- int N номер текущего звена, 
- int N_PREV номер предыдущего звена в кинематической цепи (либо 0, если такого звена нет)
- double POS_L положение захвата относительно этого звена, 
- double POS_ALPHA направление центра захвата (рад), 
- double STATE_ALPHA текущее состояние (угол раскрытия, рад). 

Необходимо уметь:
регистрировать открытие/закрытие захвата, т.е. установку его в заданный угол раскрытия.

### Видеокамера: 
содержит:
- int  N номер звена, 
- int N_PREV номер предыдущего звена, 
- int ALPHA ориентацию оптической оси относительно предыдущего звена (угол), 
- int ALPHA_FI угол раствора изображения.

### Манипулятор: 
упорядоченный по номеру звена список звеньев. 
Должен позволять задание угла поворота для произвольного звена и открытие/закрытие захватов. 
Также должен уметь рассчитывать положение любого указанного звена и избегать некорректно составленных описаний (кольцевых зависимостей звеньев).

### Элементарное движение: 
описывает перемещение одного звена манипулятора от текущего угла поворота к указанному. Если в процессе перемещения некоторые звенья манипулятора столкнутся с другими, элементарное движение считается недопустимым и не осуществляется.
Перемещение: 
набор исполняемых последовательно элементарных движений. Необходимо вычислять конечное положение манипулятора после перемещения, если все его элементарные движения выполнимы.
