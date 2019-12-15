// _ _ _ _ _ _ _ _ _ _ _ _ _ _  /¯¯¯ Canary ¯¯¯\_ _ _ _ _ _ _ _ _ _ _ _ _ _  //

// var config = {
//     type: Phaser.AUTO,
//     width: 800,
//     height: 600,
//     physics: {
//         default: 'arcade',
//         arcade: {
//             gravity: { y: 200 }
//         }
//     },
//     scene: {
//         preload: preload,
//         create: create
//     }
// };

// var game = new Phaser.Game(config);

// function preload() {
//     this.load.setBaseURL('http://labs.phaser.io');

//     this.load.image('sky', 'assets/skies/space3.png');
//     this.load.image('logo', 'assets/sprites/phaser3-logo.png');
//     this.load.image('red', 'assets/particles/red.png');
// }

// function create() {
//     this.add.image(400, 300, 'sky');

//     var particles = this.add.particles('red');

//     var emitter = particles.createEmitter({
//         speed: 100,
//         scale: { start: 1, end: 0 },
//         blendMode: 'ADD'
//     });

//     var logo = this.physics.add.image(400, 100, 'logo');

//     logo.setVelocity(100, 200);
//     logo.setBounce(1, 1);
//     logo.setCollideWorldBounds(true);

//     emitter.startFollow(logo);
// }


// ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯  \_ _ Canary _ _/¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯  //

// import * as Phaser from 'phaser';


let config = {
    type: Phaser.AUTO,
    width: 800,
    height: 600,
    physics: {
        default: 'arcade',
        arcade: {
            gravity: { y: 300 },
            debug: false
        }
    },
    scene: {
        preload: preload,
        create: create,
        update: update
    }
};

let game = new Phaser.Game(config);

function preload() {
    this.load.image('sky', 'resources/sky.png');
    this.load.image('ground', 'resources/platform.png');
    this.load.image('star', 'resources/star.png');
    this.load.image('bomb', 'resources/bomb.png');
    this.load.spritesheet('dude', 'resources/dude.png',
        { frameWidth: 32, frameHeight: 48 });

}

let platforms;
let player;


function create() {
    this.add.image(400, 300, 'sky');

    platforms = this.physics.add.staticGroup();

    platforms.create(400, 568, 'ground').setScale(2).refreshBody();

    platforms.create(600, 400, 'ground');
    platforms.create(50, 250, 'ground');
    platforms.create(750, 220, 'ground');

    player = this.physics.add.sprite(100, 450, 'dude');
    player.setBounce(0.2);
    player.setCollideWorldBounds(true);

    this.anims.create({
        key: 'left',
        frames: this.anims.generateFrameNumbers('dude', {
            start: 0, end: 3
        }),
        frameRate: 10,
        repeat: -1
    });

    this.anims.create({
        key: 'turn',
        frames: [{
            key: 'dude', frame: 4
        }],
        frameRate: 20
    });

    this.anims.create(
        {
            key: 'right',
            frames: this.anims.generateFrameNumbers('dude', {
                start: 5, end: 8
            }),
            frameRate: 10,
            repeat: -1
        }
    );

    this.physics.add.collider(player, platforms);
}

function update() {

}
