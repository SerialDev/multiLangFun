const url = "http://127.0.0.1:2222/"

// Excalibur is loaded into the ex global namespace
import * as ex from 'excalibur'

let game = new ex.Engine({
    width: 800,
    height: 600,
}
			);

let paddle = new ex.Actor(150, game.drawHeight - 40, 200, 20);

paddle.color = ex.Color.Chartreuse;

paddle.collisionType = ex.CollisionType.Fixed;

// Add a mouse move listener
game.input.pointers.primary.on('move', (evt) => {
    paddle.pos.x = evt.target.lastWorldPos.x;
})

let ball = new ex.Actor(100, 300, 20, 20);

ball.color = ex.Color.Red;
ball.vel.setTo(100,100);
ball.collisionType = ex.CollisionType.Passive;

ball.on('precollision', (ev) => {

    if (bricks.indexOf(ev.other) > -1) {
	ev.other.kill();
    }
    let intersection = ev.intersection.normalize();
    if (Math.abs(intersection.x) > Math.abs(intersection.y)){
	ball.vel.x *= -1;
    } else {
	ball.vel.y *= -1;
    }
})

ball.on('postupdate', function() {
    if (this.pos.x < this.width /2 ) {
	this.vel.x *= -1;
    }

    if (this.pos.x + this.width / 2 > game.drawWidth) {
	this.vel.x *= -1;
    }

    if ( this.pos.y < this.height / 2){
	this.vel.y *= -1;
    }
})

ball.on('exitviewport', function() {
    alert('you lose!');
})

ball.draw = function(ctx, delta) {
    ctx.fillStyle = this.color.toString();
    ctx.beginPath();
    ctx.arc(this.pos.x, this.pos.y, 10, 0, Math.PI *2);
    ctx.closePath();
    ctx.fill();
}

// Build bricks

let padding = 40;
let xoffset = 65;
let yoffset = 20;
let cols = 5;
let rows = 4;

let brickColor = [ex.Color.Violet, ex.Color.Orange, ex.Color.Yellow];

let brickWidth  = game.drawWidth / cols - (2 *padding / cols);
let brickHeight = 30;

let bricks = [];

for (let i = 0; i < rows; ++i) {
    for (let j = 0; j < cols; ++j){
	bricks.push(new ex.Actor(
	    xoffset + i * (brickWidth + padding) + padding,
	    yoffset + j * (brickHeight + padding) + padding,
	    brickWidth,
	    brickHeight,
	    brickColor[j % brickColor.length],
	console.log(i);
    }
}

bricks.forEach((brick) =>{
    brick.collisionType = ex.CollisionType.Active;

    game.add(brick);
})

game.add(paddle);
game.add(ball);

game.start();



