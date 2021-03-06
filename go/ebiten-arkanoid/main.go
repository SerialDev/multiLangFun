package main



import (
	"github.com/hajimehoshi/ebiten"
	"fmt"
	"log"
	"bytes"
	"image"
	"github.com/hajimehoshi/ebiten/ebitenutil" // This is required to draw debug texts.
	"image/color"
	resources "github.com/hajimehoshi/ebiten/examples/resources/images/flappy"

)


var square *ebiten.Image;
var gopherImage *ebiten.Image;
var gopherImageOpts *ebiten.DrawImageOptions

type Pos struct {
	x float64
	y float64
};

type KeyMapper struct {
	up ebiten.Key
	down ebiten.Key
	left ebiten.Key
	right ebiten.Key
}


func CreateKeymap(arr []ebiten.Key) KeyMapper {
	keyMap := KeyMapper{
		up: arr[0],
		down: arr[1],
		left: arr[2],
		right: arr[3],
	}
	return keyMap;
}

var gopherpos = Pos{x:120, y:120};
var currentKeymap KeyMapper;

func movement(screen *ebiten.Image ){
	if ebiten.IsKeyPressed(currentKeymap.up){
		gopherpos.y -= 3;
		screen.DrawImage(gopherImage, gopherImageOpts);
		ebitenutil.DebugPrint(screen, "\n\n current_x: !" + fmt.Sprintf("%f", gopherpos.y)  );
		ebitenutil.DebugPrint(screen, "\nyou pressed up!");
	}
	if ebiten.IsKeyPressed(currentKeymap.down){
		gopherpos.y += 3;
		screen.DrawImage(gopherImage, gopherImageOpts);
		ebitenutil.DebugPrint(screen, "\n\n current_x: !" + fmt.Sprintf("%f", gopherpos.y)  );
		ebitenutil.DebugPrint(screen, "\nyou pressed Down!");
	}
	if ebiten.IsKeyPressed(currentKeymap.right){
		gopherpos.x += 3;
		screen.DrawImage(gopherImage, gopherImageOpts);
		ebitenutil.DebugPrint(screen, "\nyou pressed Right!");
		ebitenutil.DebugPrint(screen, "\n\n current_x: !" + fmt.Sprintf("%f", gopherpos.x)  );
	}
	if ebiten.IsKeyPressed(currentKeymap.left){
		gopherpos.x -= 3;
		screen.DrawImage(gopherImage, gopherImageOpts);
		ebitenutil.DebugPrint(screen, "\n\n current_x: !" + fmt.Sprintf("%f", gopherpos.x)  );
		ebitenutil.DebugPrint(screen, "\nyou pressed Left!");
	}

	if ebiten.IsMouseButtonPressed(ebiten.MouseButtonLeft){
		ebitenutil.DebugPrintAt(screen, "you pressed the Left mouse button", 0, 16);
	}

	if ebiten.IsMouseButtonPressed(ebiten.MouseButtonRight){
		ebitenutil.DebugPrintAt(screen, "you pressed the Right mouse button", 0, 16);
	}

}


func update(screen *ebiten.Image) error {

	currentKeymap = CreateKeymap(
		[]ebiten.Key{
			ebiten.KeyUp,
			ebiten.KeyDown,
			ebiten.KeyLeft,
			ebiten.KeyRight});

	screen.Fill(color.NRGBA{0xff, 0xf0, 0xf0, 0xff});

	ebitenutil.DebugPrint(screen, "first ebiten game!");

	if square==nil {
		square, _ = ebiten.NewImage(16, 16, ebiten.FilterNearest);
	}
	square.Fill(color.White);

	opts := &ebiten.DrawImageOptions{};
	opts.GeoM.Translate(64,64);
	screen.DrawImage(square, opts);

	img, _, err := image.Decode(bytes.NewReader(resources.Gopher_png))
	if err != nil {
		log.Fatal(err);
		ebitenutil.DebugPrintAt(screen, err.Error(), 0, -1);
	}

	gopherImage, _ = ebiten.NewImageFromImage(img, ebiten.FilterDefault);

	gopherImageOpts := &ebiten.DrawImageOptions{};
	gopherImageOpts.GeoM.Translate(gopherpos.x, gopherpos.y);
	screen.DrawImage(gopherImage, gopherImageOpts);

	movement(screen);

	return nil;
}



func main() {
	if err := ebiten.Run(update, 320, 240, 2, "Hello World!");
	err != nil{
		panic(err);
	}
}

