"use strict";
// _ _ _ _ _ _ _ _ _ _ _ _ _ _  /¯¯¯ Canary ¯¯¯\_ _ _ _ _ _ _ _ _ _ _ _ _ _  //
exports.__esModule = true;
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
var Phaser = require("phaser");
var config = {
    type: Phaser.AUTO,
    width: 800,
    height: 600,
    physiscs: {
        "default": 'arcade',
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
var game = new Phaser.Game(config);
function preload() {
    this.load.image('sky', 'resources/sky.png');
    this.load.image('ground', 'resources/platform.png');
    this.load.image('star', 'resources/star.png');
    this.load.image('bomb', 'resources/bomb.png');
    this.load.spritesheet('dude', 'resources/dude.png', { frameWidth: 32, frameHeight: 48 });
}
var platforms;
function create() {
    this.add.image(400, 300, 'sky');
    platforms = this.physiscs.add.staticGroup();
    platforms.create(400, 568, 'ground').setScale(2).refreshBody();
    platforms.create(600, 400, 'ground');
    platforms.create(50, 250, 'ground');
    platforms.create(750, 220, 'ground');
}
function update() {
}
