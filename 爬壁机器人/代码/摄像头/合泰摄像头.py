import sensor, image, time, pyb,struct, math

sensor.reset()                      # Reset and initialize the sensor.
sensor.set_pixformat(sensor.RGB565) # Set pixel format to RGB565 (or GRAYSCALE)
#sensor.set_pixformat(sensor.GRAYSCALE)#用于设置摄像头输出格式 MaixPy开发板配置的屏幕使用的是RGB565，推荐设置为RGB565格式 当前设置为灰度模式
sensor.set_framesize(sensor.QVGA)   # Set frame size to QVGA (320x240)
sensor.set_vflip(1)#设置摄像头垂直翻转 0 表示关闭垂直翻转
sensor.set_hmirror(1)#设置水平镜像 0 表示关闭水平镜像
sensor.skip_frames(time = 2000)     # Wait for settings take effect.
sensor.set_auto_gain(1,200)#设置摄像自动增益模式
clock = time.clock()               # Create a clock object to track the FPS.

#三个物块的区域
ROI1 = (29,50,80,80)
ROI2 = (109,50,80,80)
ROI3 = (189,50,77,80)
ROI4 = (29,131,80,80)
ROI5 = (109,131,80,80)
ROI6 = (189,131,80,80)

#色块阈值
balck = (56, 65, 12, 120, -2, 6)
#Threshold = ((255, 215))
#串口初始化
uart = pyb.UART(3,9600)
uart.write("acb\r\n")
#led初始化
led_red = pyb.LED(1)
led_green = pyb.LED(2)
led_blue = pyb.LED(3)
led_red.on()
time.sleep_ms(100)
led_red.off()
time.sleep_ms(100)
led_red.on()
time.sleep_ms(100)
led_red.off()
time.sleep_ms(100)
#led_green.on()
#led_blue.on()
#位置
def uart_read():
    if uart.any():  #进行串口数据的接收
            res=uart.read(1)  #表示为读取一个十六进制数,这里的uart必须是例化的·
            res = struct.unpack('B', res)
            res = hex(res)
            res = int(res)
            return res

while(True):
    clock.tick()                    # Update the FPS clock.
    #img = sensor.snapshot().binary([Threshold])
    img = sensor.snapshot()
    #画出区域便于观察
    img.draw_rectangle(ROI1)
    img.draw_rectangle(ROI2)
    img.draw_rectangle(ROI3)
    img.draw_rectangle(ROI4)
    img.draw_rectangle(ROI5)
    img.draw_rectangle(ROI6)
    #获取区域的统计信息
    #statistics1 = img.get_statistics(roi=ROI1)
    #statistics2 = img.get_statistics(roi=ROI2)
    #statistics3 = img.get_statistics(roi=ROI3)

    #获取区域内的阈值色块
    #blobs1 = img.find_blobs([balck],roi=ROI1,pixels_threshold = 5)
    #if blobs1:                                            #如果找到了目标颜色
        #FH = bytearray([0xb3,0xb4])
        #blobs1_Value = 1
        #for a in blobs1:
        ##迭代找到的目标颜色区域
            #img.draw_cross(a[5], a[6])                  #画十字 cx,cy
##            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
##            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            #img.draw_edges(a.min_corners(), color=(0,255,0))#画框
    #else:
    blobs1_Value=0
    blobs2 = img.find_blobs([balck],roi=ROI2,pixels_threshold = 5)
    if blobs2:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])
        blobs2_Value = 1
        for b in blobs2:
        #迭代找到的目标颜色区域
            img.draw_cross(b[5], b[6])                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(b.min_corners(), color=(0,255,0))#画框
    else:
        blobs2_Value=0
    blobs3 = img.find_blobs([balck],roi=ROI3,pixels_threshold = 2)
    if blobs3:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])
        blobs3_Value = 1
        for c in blobs3:
        #迭代找到的目标颜色区域
            img.draw_cross(c[5], c[6])                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(c.min_corners(), color=(0,255,0))#画框
    else:
        blobs3_Value=0
    blobs4 = img.find_blobs([balck],roi=ROI4,pixels_threshold = 3)
    if blobs4:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])
        blobs4_Value = 1
        for d in blobs4:
        #迭代找到的目标颜色区域
            img.draw_cross(d[5], d[6])                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(d.min_corners(), color=(0,255,0))#画框
    else:
        blobs4_Value=0
    blobs5 = img.find_blobs([balck],roi=ROI5,pixels_threshold = 5)
    if blobs5:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])
        blobs5_Value = 1
        for f in blobs5:
        #迭代找到的目标颜色区域
            img.draw_cross(f[5], f[6])                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(f.min_corners(), color=(0,255,0))#画框
    else:
        blobs5_Value=0
    blobs6 = img.find_blobs([balck],roi=ROI6,pixels_threshold = 2)
    if blobs6:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])
        blobs6_Value = 1
        for g in blobs6:
        #迭代找到的目标颜色区域
            img.draw_cross(g[5], g[6])                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(g.min_corners(), color=(0,255,0))#画框
    else:
        blobs6_Value=0
    date = uart_read()
    if date == 49:
        date = 0
        if (blobs1_Value == 1):
            uart.write(str(1))
            time.sleep_ms(500)
        elif (blobs2_Value == 1):
            uart.write(str(2))
            time.sleep_ms(500)
        elif (blobs3_Value == 1):
            uart.write(str(3))
            time.sleep_ms(500)
        elif (blobs4_Value == 1):
            uart.write(str(4))
            time.sleep_ms(500)
        elif (blobs5_Value == 1):
            uart.write(str(5))
            time.sleep_ms(500)
        elif (blobs6_Value == 1):
            uart.write(str(6))
            time.sleep_ms(500)


    print(blobs1_Value,blobs2_Value,blobs3_Value,blobs4_Value,blobs5_Value,blobs6_Value)

