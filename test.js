var wrcard = require('./lib/wrcard');

var getCarId = function () {
    console.log(wrcard.getCardId(5));
}

var writeCard = function () {
    var card = {
        nRoom: '1101',
        Wstartdate: '200901010830',
        Wenddate: '201901010830',
        Vioce: '1',
        Obt: '0',
        Op: '8888',
        nCode: '1',
        jLift: ''
    };
    var result = wrcard.w_Card(card.nRoom, card.Wstartdate, card.Wenddate, card.Vioce, card.Obt, card.Op, card.nCode, card.jLift);
    if (result == 1) {
        console.log('д���ɹ���');
    } else {
        console.log('д��ʧ�ܣ�');
    }
}

var readCard = function () {
    var carText = wrcard.r_Card();
    console.log(carText);
}

var woffCard = function () {
    var result = wrcard.woff_Card();
    if (result == 1) {
        console.log('�����ɹ���');
    } else {
        console.log('����ʧ�ܣ�');
    }
}

getCarId();

process.on('uncaughtException', function (err) {
    console.log(err);
});

process.stdin.resume();