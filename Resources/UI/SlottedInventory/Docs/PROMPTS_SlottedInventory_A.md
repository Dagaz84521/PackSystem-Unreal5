# 生成记录

模式：内置 imagegen。未使用 CLI/API fallback，未调用额外 API key。
输入风格参考：Reference/Approved_Style_Preview.png（用户选定的完整预览）。
以下记录采用的最终提示词；未将含白色留白的底条草稿纳入交付。

## Chest 与 Slot_Normal 的共同前后缀

Use case: ui-mockup. Asset type: production game UI raster PNG, NOT a screenshot or presentation. Image 1 is STYLE REFERENCE ONLY, user approved this exact charcoal and muted aged-gold wuxia UI. Create only the following standalone component:

[此处插入下方对应组件提示词]

Preserve the reference's dark palette, hand-worn fine texture and thin elegant off-white old-gold linework. NO scene background, NO text whatsoever, NO watermark, NO sample item icons, NO montage or sprite sheet. Export actual alpha where transparent, never paint a fake checkerboard. One asset only.

说明：虽然提示词请求了 Alpha，实际输出检查为 RGB 不透明图，本包按不透明底图交付，不宣称透明素材。

## T_UI_Chest_Background

A SINGLE blank chest inventory panel BACKPLATE. Match the upper chest window outer frame in the reference, but REMOVE every inventory slot, all icons, all numbers, the title, and the X button. Request output 1024 x 1152 pixels, an upright nearly-square rectangle (8:9 aspect). Artwork fills canvas edge-to-edge with tiny transparent antialiased exterior if needed, no large margin. A delicate worn ivory-old-gold rectangular outer border with small squared Chinese meander motifs at all four corners. Interior opaque charcoal near-black subtly textured aged paper/lacquer. At about 16 percent of panel height add one very subtle thin old-gold horizontal header separator inset from both side edges. Leave the header completely blank for dynamic text and close button. Leave the entire lower body blank for dynamically placed 3-by-3 slots; NO internal boxes, NO grid, NO decorative center image. Flat front-facing, symmetric, crisp and understated.

来源：exec-013dc584-1daf-40fd-aaef-c8aca7b4c132.png。

## T_UI_Slot_Normal

A SINGLE empty square inventory slot in NORMAL state, extracted stylistically from one of the empty individual cells in the reference, NOT the ornate container outer frame. Request square 1024 x 1024 pixels. Artwork fills the canvas almost edge-to-edge. Thin muted aged ivory-bronze outline (about 10 pixels in 1024), tiny stepped/chamfered inset corners, elegant restrained wuxia. Completely EMPTY opaque near-black charcoal finely textured interior. No item, no numerals, no lettering, no icons, no panels within this slot, no meander corner ornaments, no glow. All four sides equal and straight. Any exterior beyond thin border must be true alpha transparency, not a checkerboard graphic; exterior padding no more than 8 pixels. Flat front-facing texture asset, no perspective, no floor shadow. This is the master geometry for three later interaction-state variants, so centered perfectly symmetric square and stable canvas footprint.

来源：exec-b8709e5d-8564-4d93-bca8-7b075fd037d8.png。

## 三种状态编辑的共同前后缀

输入：T_UI_Slot_Normal 对应的生成原图，作为 edit target。

Use case: precise-object-edit. Image 1 is the edit target: a square game inventory slot texture. Produce one standalone square UI PNG texture, not a mockup.

[此处插入下方对应状态提示词]

LOCK all geometry and proportions: identical 1254x1254 square canvas, identical border path and same stepped corners at exactly the same positions, keep texture grain and composition, do not redraw a different frame, do not crop or add padding. Preserve empty center and existing black outer corner areas. NO text, icons, numbers, decorations, or extra elements. Only the single square slot fills the output.

### T_UI_Slot_Hovered

Change ONLY the normal interaction colors into HOVERED state: outline becomes pale ivory, and inside gains a faint translucent milky-white wash over the charcoal grain, restrained and still dark enough for item icons. A very small subtle inward light around border, no outside glow. Not yellow-gold selected state.

来源：exec-038279c5-012d-44b1-bed3-038c069e3bca.png。

### T_UI_Slot_Pressed

Change ONLY interaction colors into PRESSED state: darken the charcoal center modestly, and subdue the outline to darker muted old-bronze, creating a slightly pressed/darker feeling by color alone. Do NOT move or scale or offset any edges. No glow.

来源：exec-8387a6fe-60db-460a-bb93-6c201f15867a.png。

### T_UI_Slot_Selected

Change ONLY interaction colors into SELECTED state: brighten the outline to warm pale antique gold, with a subtle tight warm inner glow just inside the existing line. Keep center dark charcoal. Elegant very subdued gold, not saturated yellow. No flare, no sparks, no large outer glow.

来源：exec-be1a42fa-bfb5-4fb7-915a-71d09ef55971.png。

## T_UI_Hotbar_Background（去除外部留白后的最终版本）

输入：先前生成的长条底板草稿 exec-bfdb6235-a96b-48fb-b422-082c52efb73d.png。

Use case: precise-object-edit. Image 1 is a source style reference of a charcoal and ivory-old-gold inventory backplate. Make ONE production raster backplate texture as a FULL BLEED RECTANGULAR TEXTURE, no environment, not an isolated object floating on white. Output landscape 3:1 aspect ratio. The OUTER RECTANGULAR GOLD FRAME must coincide with the OUTERMOST IMAGE BOUNDARIES. Fill the entire image with the black textured panel: NO WHITE PIXELS, NO WHITE SPACE, NO TRANSPARENT MARGINS, NO LARGE EXTERIOR OF ANY COLOR, NO SHADOW BELOW IT. Imagine zooming/cropping into the source until the frame touches every edge of the image. This is a nine-slice scalable UI backplate source texture: small matching Chinese right-angle meander motifs at each of the four extreme outer corners; thin restrained aged-ivory-gold line along every canvas edge; center empty continuous finely textured near-black charcoal aged paper/lacquer. Keep all four corners intact, not clipped. Match source style exactly, no increased ornamentation. No grid or internal cells, no title band, no text, no icon, no division lines, no handwriting, no watermark. The whole image IS the rectangular panel. It will later be stretched as a UI brush to hold ten slots.

来源：exec-1bbe98c7-c4b1-4f53-8a7e-7ce3ba6d1762.png。

