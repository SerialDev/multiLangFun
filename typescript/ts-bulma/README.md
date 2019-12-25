Run

```
npm install --save-dev parcel-bundler parcel-plugin-typescript typescript
```

Create a tsconfig.json: 
```
{ "compilerOptions": { "module": "commonjs", "esModuleInterop": true, "target": "es5", "lib": [ "es6", "dom" ] }, "include": [ "./src/**/*" ] }
```

Create an index.html: 
```
<!doctype html> <html> <head> <meta charset="UTF-8"> </head> <body> <script src="./src/index.ts"></script> </body> </html>
```
Finally, create the src/index.ts:

Run with: 
```
npx parcel index.html
```
Create a static build with: 
```
npx parcel build --public-url=./ --detailed-report index.html
```