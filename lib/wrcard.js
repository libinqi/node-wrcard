/**
 * Created by libinqi on 2015/6/18.
 */
var wrcard = require('../bin/wrcard.node');

/**
 * 读取卡ID
 *
 * @param nCom // 字符串类型,制卡机与电脑的通讯端口号,运行制卡软件时会提示该通讯口号,可以查看到.(比如1、2、3、4、5、6、7等)
 * @returns 返回值为字符串类型,返回值长度等于8时表示成功读取了卡ID,其他长度值为读取卡ID失败
 */
exports.getCardId = function (nCom) {
    try {
        return wrcard.Getcardid(nCom);
    }
    catch (ex) {
        console.log(ex);
    }
};

/**
 * 销卡
 *
 * @returns
 * 74:请拔出设定器再操作
 * 75:无卡
 * 76:附加数据长度不符
 * 77:读数据块出错/操作失败
 * 78:M1卡扇区密钥比对错误
 * 51:数据解密错误
 * 0:通讯错误(制卡机未连接)
 * 1:表示注销卡成功
 */
exports.woff_Card = function () {
    try {
        return wrcard.Woff_Card();
    }
    catch (ex) {
        console.log(ex);
    }
};

/**
 * 读卡
 *
 * @returns
 * 80:查询无该卡制卡记录信息
 * 72:连接发卡系统数据库失败
 * WOFF:表示该卡已经注销
 * 74:请拔出设定器再操作
 * 75:无卡
 * 76:附加数据长度不符
 * 77:读数据块出错/操作失败
 * 78:M1卡扇区密钥比对错误
 * 51:数据解密错误
 * 0:通讯错误(制卡机未连接)
 * 读卡成功返回以ok开头的以符号+连接的一系列字符串
 */
exports.r_Card = function () {
    try {
        return wrcard.r_Card();
    }
    catch (ex) {
        console.log(ex);
    }
};

/**
 *
 * 写卡
 *
 * @param card:
 * {
 *     nRoom:'',// 字符串类型,房间号
 *     Wstartdate:'',// 字符串类型,开门卡启用时间,格式yyyymmddhhmm,比如200901010830,如果遇到时间问题不能开门，建议把这个参数设置为000000000000
 *     Wenddate:'',// 字符串类型,开门卡截止时间,格式yyyymmddhhmm,比如200912301200
 *     Vioce:'',// 字符串类型,是否带开门声音,设置为1表示带开门声音,0表示不带开门声音
 *     Obt:'',// 字符串类型,是否带弱电告警,设置为1表示带弱电告警,0表示不带弱电告警
 *     Op:'',// 字符串类型,房间号
 *     nCode:'',// 整型,使用新码或原码制卡,设置为1表示使用新码制卡,设置为0表示使用原码制卡;使用新码制的开门卡成功开过门后将会限制之前的所有客人开门卡,使用原码制的客人卡不会限制之前的开门卡(使用原码制卡可以理解为对之前制的客人卡的复制卡)。
 *                 如果一个客房只给客人发一张开门卡，则用新码(即参数设置为1)，如要发2张或2张以上的开门卡，则发第一张开门卡时用新码(即参数设置为1)，第二张开始用原码(即参数设置为0)
 *     jlift:''// 字符串类型,电梯参数1+2+3+E+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21+22+23+24+25+26+27+28+29+30表示该开门卡对电梯的1到30层楼有效(共支持64层电梯),如无电梯该参数请填0
 *                参数中的1、2、3、E、5等表示电梯楼层位置，可由任意字符表示，由加好(+)连接；电梯楼层位置必须和制卡软件中设置的电梯楼层位置一一对应,否则制卡时电梯信息可能无效.所以在酒店管理系统中也应建立电梯楼层位置信息库(类似客房号).
 * }
 * @returns
 * 70:起始日期格式错误
 * 71:截止日期格式错误
 * 72:连接发卡系统数据库失败
 * 73:系统无该房间号
 * 74:请拔出设定器再操作
 * 75:无卡
 * 76:附加数据长度不符
 * 77:读数据块出错/操作失败
 * 78:M1卡扇区密钥比对错误
 * 51:数据解密错误
 * 0:通讯错误(制卡机未连接)
 * 1:写卡成功
 */
exports.w_Card = function (nRoom, Wstartdate, Wenddate, Vioce, Obt, Op, nCode, jLift) {
    try {
        return wrcard.w_Card(nRoom, Wstartdate, Wenddate, Vioce, Obt, Op, nCode, jLift);
    }
    catch (ex) {
        console.log(ex);
    }
};