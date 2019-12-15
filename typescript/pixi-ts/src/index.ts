// _ _ _ _ _ _ _ _ _ _ _ _ _ _  /¯¯¯ Canary ¯¯¯\_ _ _ _ _ _ _ _ _ _ _ _ _ _  //

import * as PIXI from 'pixi.js'


// window.PIXI = PIXI; // some bundlers might prefer "global" instead of "window"


// const app = new PIXI.Application({ transparent: true });
// document.body.appendChild(app.view);

// // create a new Sprite from an image path.
// const bunny = PIXI.Sprite.from('resources/bunny.png');

// // center the sprite's anchor point
// bunny.anchor.set(0.5);

// // move the sprite to the center of the screen
// bunny.x = app.screen.width / 2;
// bunny.y = app.screen.height / 2;

// app.stage.addChild(bunny);

// app.ticker.add(() => {
//     // just for fun, let's rotate mr rabbit a little
//     bunny.rotation += 0.1;
// });


// ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯  \_ _ Canary _ _/¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯ ¯  //

import * as PIXI from 'pixi.js'

window.PIXI = PIXI;  // Some bundlers might prefer "global" instead of "window"



function Far(texture, width, height) {
    PIXI.TilingSprite.call(this, texture, width, height);
    this.position.x = 0;
    this.position.y = 0;
    this.tilePosition.x = 0;
    this.tilePosition.y = 0;
}

Far.prototype = Object.create(PIXI.TilingSprite.prototype);
Far.prototype.update = function(){
    this.tilePosition.x -= 0.128;
}

const app = new PIXI.Application({
    width: 800,
    height: 600,
// transparent: true,
    backgroundColor: 0x1099bb,
    resolution: window.devicePixelRatio || 1,
})

document.body.appendChild(app.view);

let container = new PIXI.Container();

app.stage.addChild(container);

const farTexture = PIXI.Texture.from('resources/bg-far.png');
let far = new Far(farTexture, 512, 256);
container.addChild(far);


let midTexture = PIXI.Texture.from('resources/bg-mid.png');
// let mid = new PIXI.Sprite(midTexture);
let mid = new PIXI.TilingSprite(midTexture,
			        512,
			        256);
mid.position.x = 0;
mid.position.y = 128;
mid.tilePosition.x = 0;
mid.tilePosition.y = 0;
container.addChild(mid);

requestAnimationFrame(update);

function update() {
    // far.tilePosition.x -= 0.128;
    far.update();
    mid.tilePosition.x -= 0.64;
    requestAnimationFrame(update);
}


function createDragAndDropFor(target){  
  target.interactive = true;
  target.on("mousedown", function(e){
    drag = target;
  })
  target.on("mouseup", function(e){
    drag = false;
  })
  target.on("mousemove", function(e){
    if(drag){
      drag.position.x += e.data.originalEvent.movementX;
      drag.position.y += e.data.originalEvent.movementY;
    }
  })
}

let drag = false;  

createDragAndDropFor(mid);



update();
