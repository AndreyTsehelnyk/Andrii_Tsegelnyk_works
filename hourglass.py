from time import *
from tkinter import *
from turtle import *
from tkinter.messagebox import *

window = Tk()

class Sand():

    def __init__(self):
        self.y = -90
        self.sand = 0
        self.count = 0
        self.layer = 30
        self.layer1 = 30
        self.sand1 = 0
        self.y = -90
        self.y1 = 35

    def put_grain(self):
        self.layers()
        self.layer = 30
        self.layer1 = 30
        self.sand = 0
        self.sand1 = 0
        self.y = -90
        self.y1 = 35
        self.count = 0
        self.erase()
        showinfo(message="ЧАС ВИЧЕРПАНО!")


    def layers(self):
        draw.penup()
        draw.pencolor('gold')
        draw.goto(0, 0)
        draw.pendown()
        draw.goto(0, self.y)
        draw.right(150)
        for j in range(10):
            for i in range(self.layer):
                self.count +=1
                self.sand += 3
                draw.forward(self.sand)
                draw.right(180)
                if self.count == self.layer:
                    self.remove()
                    self.next()

    def remove(self):
        draw.penup()
        draw.goto(0, self.y1)
        draw.pencolor('white')
        draw.pendown()
        for i in range(self.layer):
            self.sand1 += 2
            draw.forward(self.sand1)
            draw.right(180)
        draw.pencolor('gold')

    def erase(self):
        draw.penup()
        draw.goto(0, 0)
        draw.pencolor('white')
        draw.pendown()
        draw.goto(0, -60)
        draw.goto(0, 0)
        draw.left(90)
        h.sandrrev('white')

        normalButton(Run_Button)
        normalButton(tim)
        normalButton(Info_Button)

    def next(self):
        self.layer -= 3
        self.layer1 -= 3
        self.sand = 0
        self.sand1 = 0
        self.count = 0
        self.y += 3
        self.y1 -= 3
        draw.penup()
        draw.goto(0, self.y)
        draw.right(180)
        draw.pendown()
        try:
            sleep( (int(tim.get())*60-49)/10 )
        except ValueError:
            pass

class Hourglass:

    def __init__(self):
        self.i = 0

    def draw(self):
        draw.pensize(5)
        draw.penup()
        draw.pencolor('saddle brown')
        draw.fillcolor('saddle brown')

        disableButton(Run_Button)
        disableButton(tim)
        disableButton(Info_Button)

        draw.goto(-10, 0)
        draw.left(90)
        draw.pendown()
        draw.forward(10)
        draw.left(60)
        draw.forward(50)
        draw.right(60)
        draw.forward(70)
        draw.right(90)
        draw.penup()

        draw.goto(10,0)
        draw.pendown()
        draw.right(270)
        draw.forward(10)
        draw.right(60)
        draw.forward(50)
        draw.left(60)
        draw.forward(70)
        draw.left(90)
        draw.begin_fill()
        draw.forward(115)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(125)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(10)
        draw.end_fill()
        draw.penup()

        draw.goto(-10, 0)
        draw.pendown()
        draw.right(270)
        draw.right(60)
        draw.forward(50)
        draw.left(60)
        draw.forward(70)
        draw.begin_fill()
        draw.left(90)
        draw.forward(115)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(125)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(10)
        draw.end_fill()
        draw.penup()
        draw.goto(10, 0)
        draw.pendown()
        draw.right(30)
        draw.forward(50)
        draw.right(60)
        draw.forward(70)

        if self.i == 0:
            self.sand()
            normalButton(Run_Button)
            normalButton(tim)
            normalButton(Info_Button)

    def sand(self):
        draw.penup()
        draw.pencolor('gold')
        draw.fillcolor('gold')
        draw.goto(30,0)
        draw.forward(90)
        draw.begin_fill()
        draw.right(90)
        draw.pendown()
        for i in range(3):
            draw.forward(60)
            draw.right(120)
        draw.end_fill()

    def sandrev(self):
        draw.penup()
        draw.pencolor('gold')
        draw.fillcolor('gold')
        draw.goto(0, -30)
        draw.left(180)
        draw.forward(40)
        draw.pendown()
        draw.begin_fill()
        draw.forward(70)
        draw.left(90)
        draw.forward(18)
        draw.left(90)
        draw.forward(60)
        draw.left(60)
        draw.forward(17)
        draw.right(60) #left30 это смотрит вверх
        draw.end_fill()

    def turn(self):
        draw.penup()

        draw.pencolor('saddle brown')
        draw.fillcolor('saddle brown')

        draw.goto(-10, -10)
        draw.pendown()
        draw.forward(10)
        draw.left(60)
        draw.forward(50)
        draw.right(60)
        draw.forward(70)
        draw.right(90)
        draw.penup()

        draw.goto(-10, 10)
        draw.pendown()
        draw.right(270)
        draw.forward(10)
        draw.right(60)
        draw.forward(50)
        draw.left(60)
        draw.forward(70)
        draw.left(90)
        draw.begin_fill()
        draw.forward(115)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(125)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(10)
        draw.end_fill()
        draw.penup()

        draw.goto(-10, -10)
        draw.pendown()
        draw.right(270)
        draw.right(60)
        draw.forward(50)
        draw.left(60)
        draw.forward(70)
        draw.begin_fill()
        draw.left(90)
        draw.forward(115)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(125)
        draw.right(90)
        draw.forward(10)
        draw.right(90)
        draw.forward(10)
        draw.end_fill()
        draw.penup()
        draw.goto(-10, 10)
        draw.pendown()
        draw.right(30)
        draw.forward(50)
        draw.right(60)
        draw.forward(70)
        draw.penup()

    def sandrrev(self, color= 'gold'):
        draw.penup()
        draw.pencolor(color)
        draw.fillcolor(color)
        draw.goto(-5, 0)
        draw.pendown()
        draw.begin_fill()
        draw.left(90)
        draw.forward(10)
        draw.left(90)
        draw.forward(13)
        draw.right(60)
        draw.forward(40)
        draw.left(150)
        draw.forward(80)
        draw.left(150)
        draw.forward(40)
        draw.right(60)
        draw.forward(13)
        draw.left(45)
        draw.forward(5)
        draw.left(45)
        draw.forward(5)
        draw.left(45)
        draw.forward(5)
        draw.right(75)
        draw.end_fill() #-30

    def startturning(self):
        try:
            if int(tim.get()) < 1:
                showinfo(message='НАТИСНІТЬ ОК ЩОБ ПОЧАТИ ВІДЛІК 1 ХВИЛИНА')
            else:
                showinfo(message='НАТИСНІТЬ ОК ЩОБ ПОЧАТИ ВІДЛІК %d ХВИЛИН' % int(tim.get()))
            disableButton(Run_Button)
            disableButton(tim)
            draw.clear()
            self.turn()
            self.sandrev()
            sleep(2)
            draw.clear()
            draw.penup()
            self.i += 1
            self.draw()
            self.sandrrev()
            s.put_grain()
            sleep(2)
            draw.right(150)
        except:
            showinfo(message="БУДЬ ЛАСКА, ВВЕДІТЬ КОРЕКТНЕ ЗНАЧЕННЯ")
            normalButton(Run_Button)
            normalButton(tim)

def info():
    showinfo('ПРАВИЛА КОРИСТУВАННЯ', '1. Для пуску натисніть "Run", для виходу - "Quit"\n'
                                     '2. Мінімальний таймер: 1 хвилина.\n'
                                     'Якщо Ви введете число менше 1, таймер автоматично запуститься на 1 хвилину.\n'
                                     '4. Відлік починається тоді, коли починає сипатись пісок.\n'
                                     'Приємного користування!:)')

def disableButton(my_button):
    my_button.config(state='disabled')
def normalButton(my_button):
    my_button.config(state='normal')

h = Hourglass()
s = Sand()

canvas = Canvas(window, width=400, height=400)
canvas.grid(padx=2, pady=2, row=0, column=0, rowspan=10, columnspan=10)
draw = RawTurtle(canvas)

L = Label(window, text='Введіть час(хв)', font=('Times New Roman', 14))
L.grid(padx=2, pady=2, row=1, column=11, sticky='nsew')

tim = Entry(window, fg='black', font=('Times New Roman', 14),width=1,bd=1,justify=CENTER)
tim.grid(padx=2, pady=2, row=2, column=11, sticky='nsew')

Info_Button = Button(window, text = 'Info', font=('Times New Roman', 14), command=info)
Info_Button.config(bg='grey', fg="black")
Info_Button.grid(padx=2, pady=2, row=10, column=11, sticky='nsew')

Run_Button = Button(window, text="Run", font=('Times New Roman', 14), command=h.startturning)
Run_Button.config(bg='grey', fg="black")
Run_Button.grid(padx=2, pady=2, row=3, column=11, sticky='nsew')

Quit_Button1 = Button(window, text="Quit", font=('Times New Roman', 14), command=window.quit)
Quit_Button1.config(bg="#B52F08", fg="black")
Quit_Button1.grid(padx=2, pady=2, row=4, column=11, sticky='nsew')


if __name__ == '__main__':

    tim.focus()

    h = Hourglass()
    draw.ht()
    draw.speed(8)
    h.draw()

    window.mainloop()
    window = Tk()