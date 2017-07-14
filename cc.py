question=raw_input( "欢迎使用计算器，请输入计算式子，退出请输q：")
while True:
    print eval(question)
    question=raw_input()
    if question=='q':
      break
